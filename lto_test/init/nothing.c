#include <stdio.h>
#include <stdlib.h>

extern char *PROF_IN_bbmap[];
struct PROF_wrapper_t {
  void *(*start_routine)(void*);
  void *arg;
};

void PROF_IN_preblock() {
  fprintf(stderr, "** PROF_IN_preblock **");
}

void PROF_IN_postblock() {
  fprintf(stderr, "** PROF_IN_postblock **");
}

void PROF_IN_init_module() {
  fprintf(stderr, "** PROF_IN_init_module **\n");
  char **p;
  int i;
  for (i = 0, p = PROF_IN_bbmap; *p; ++p, ++i) {
    fprintf(stderr, "bb=%d is %s\n", i, *p);
  }
}

void PROF_IN_init_thread() {
  fprintf(stderr, "** PROF_IN_init_thread **\n");
}

void *PROF_shim_start_routine(void *wrapped_arg) {
  struct PROF_wrapper_t *wa = (struct PROF_wrapper_t*)(wrapped_arg);
  PROF_IN_init_thread();
  void *ret = wa->start_routine(wa->arg);
  free(wrapped_arg);
  return ret;
}

void PROF_IN_sample(int bb_id) {
  fprintf(stderr, " ** PROF_IN_sample: my name is %s **\n",
      PROF_IN_bbmap[bb_id]);
}
