#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define PROF_MAX_THREADS 16

#include <string.h>
#include <errno.h>
#define DIE_IF(exp) do { if(exp) { fprintf(stderr, "System call in instrumented code failed at %s:%d. %s: %s\n", __FILE__, __LINE__, #exp, strerror(errno)); abort(); } } while (0)
#define DIE_NZ(p)   DIE_IF((p) != 0)
#define DIE_NULL(p) DIE_IF((p) == NULL)

// Basic block names
extern char *PROF_bbmap[];
extern const int PROF_nbbs;

// Size calculations, in terms of uint32_t
// Everything defined in terms of PROF_nbbs and PROF_MAX_THREADS
#define PER_THREADCOUNT_N PROF_nbbs
#define PER_THREAD_N (PROF_MAX_THREADS * PER_THREADCOUNT_N)
#define PROFILE_N (PROF_MAX_THREADS * PER_THREAD_N)

// Atexit handlers
static pthread_key_t k_thread_exit;

// Histograms
static uint32_t *PROF_hist;
 __thread static uint32_t *PROF_thread_hist;

// volatile pointer to nonvolatile
typedef uint32_t * volatile atomic_ptr_uint32_t __attribute__ ((aligned(8)));
typedef volatile uint32_t atomic_uint32_t __attribute ((aligned(8)));
static atomic_ptr_uint32_t PROF_curr_thread_hist;
static atomic_uint32_t PROF_n_offset;

#define PROF_INC_OFFSET() __sync_add_and_fetch(&PROF_n_offset, PER_THREADCOUNT_N)
#define PROF_DEC_OFFSET() __sync_sub_and_fetch(&PROF_n_offset, PER_THREADCOUNT_N)

#define PROF_INC_CURR() __sync_add_and_fetch(&PROF_curr_thread_hist, (atomic_ptr_uint32_t)(sizeof(uint32_t) * PER_THREAD_N))
#define PROF_DEC_CURR() __sync_sub_and_fetch(&PROF_curr_thread_hist, (atomic_ptr_uint32_t)(sizeof(uint32_t) * PER_THREAD_N))

struct PROF_wrapper_t {
  void *(*start_routine)(void*);
  void *arg;
};

// Timing
static struct tm start_time;

// Atexit handler functions
static void handle_thread_exit(void *p) {
  PROF_DEC_OFFSET();
  PROF_DEC_CURR();
}

// ====================
// WRITING OUT TO FILE
// ====================
static void merge_hists() {
  int i, t;
  uint32_t *curr_hist;
  for (t = 1; t < PROF_MAX_THREADS; t++) {
    curr_hist = PROF_hist + t*PER_THREAD_N;
    for (i = 0; i < PER_THREAD_N; i++) {
      PROF_hist[i] += curr_hist[i];
    }
  }
}

#define DATE_LEN 16
#define OUTPATH_LEN 512
static void out_filename(char *buf, int buflen, const char *basename) {
  static char empty[] = "";
  char datebuf[DATE_LEN];
  strftime(datebuf, DATE_LEN, "%m-%d_%H:%M:%S", &start_time);
  char *outpath;
  if (!(outpath = getenv("PROF_OUTPATH"))) {
    outpath = empty;
  }
  snprintf(buf, buflen, "%s%s_%s.out", outpath, basename, datebuf);
}

// Will return correctly, or the whole program dies.
static FILE *out_file(const char *basename) {
  char outpath[OUTPATH_LEN];
  out_filename(outpath, OUTPATH_LEN, basename);
  FILE *out = fopen(outpath, "w");
  DIE_NULL(out);
  return out;
}

// histogram format (binary)
// assume machine endianess
// Bytes | Data Type | Name
// -------------------------
// 0-3   | uint32    | nbbs
// 4-7   | uint32    | nthreads
// 8-11  | uint32    | type of profile (0 = active; 1 = working)
// 12-n  | uint32[]  | data, where n = 12 + 4*PER_THREAD_N
// n+1-  | char      | basic block names; each string is null-terminated

static void write_histogram() {
  // Merge histograms before writing
  merge_hists();
  
#ifdef PROF_W
  char *name = "working";  
#else
  char *name = "active";
#endif

  uint32_t nthreads = PROF_MAX_THREADS;
#ifdef PROF_W
  uint32_t type = 0;
#else
  uint32_t type = 1;
#endif

  FILE *f = out_file(name);
  fwrite(&PROF_nbbs, 4, 1, f);
  fwrite(&nthreads,  4, 1, f);
  fwrite(&type,      4, 1, f);
  fwrite(PROF_hist,  4, PER_THREAD_N, f);
  char **p = PROF_bbmap;
  while (*p) {
    fputs(*p, f);
    fputc(0, f); // reinsert a null termination
    ++p;
  }
  DIE_NZ(fclose(f));
}

// ============================ 
// INSTRUMENTATION ENTRY POINTS 
// ============================
 void PROF_preblock() {
#ifdef PROF_W 
   PROF_DEC_OFFSET();
#endif
}

void PROF_postblock() { 
#ifdef PROF_W
  PROF_DEC_OFFSET(); 
#endif
} 

void PROF_init_module() {
  time_t start = time(NULL);
  DIE_NULL(localtime_r(&start, &start_time));

  // Remember to write stuff at program end
  DIE_NZ(atexit(write_histogram));

  // Set up the histograms
  PROF_hist = calloc(PROFILE_N, sizeof(uint32_t));
  DIE_NULL(PROF_hist);
  // Each thread initialization does add_and_fetch, so we start at index "-1".
  PROF_curr_thread_hist = PROF_hist;
  PROF_n_offset = 0;
  PROF_thread_hist = PROF_hist;
  
  // Handle thread-specific stuff
  DIE_NZ(pthread_key_create(&k_thread_exit, handle_thread_exit));
}

void PROF_init_thread() {
  PROF_INC_OFFSET(); 
  // Set the k_thread_exit to a dummy value (which we'll never use)
  DIE_NZ(pthread_setspecific(k_thread_exit, (void *) 1));
  PROF_thread_hist = PROF_INC_CURR();
}

void *PROF_shim_start_routine(void *wrapped_arg) {
  struct PROF_wrapper_t *wa = (struct PROF_wrapper_t*)(wrapped_arg);
  PROF_init_thread();
  void *ret = wa->start_routine(wa->arg);
  free(wrapped_arg);
  return ret;
}

void PROF_sample(int bb_id) {
  PROF_thread_hist[PROF_n_offset + bb_id]++;
}

