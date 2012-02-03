#include <stdio.h>
#include <stdlib.h>

struct PROF_wrapper_t {
  void *(*start_routine)(void*);
  void *arg;
};

void PROF_IN_init_module() {
  fprintf(stderr, "** called PROF_IN_init_module **\n");
}

void PROF_IN_init_thread() {
  fprintf(stderr, "** called PROF_IN_init_thread **\n");
}

void *PROF_shim_start_routine(void *wrapped_arg) {
  struct PROF_wrapper_t *wa = (struct PROF_wrapper_t*)(wrapped_arg);
  PROF_IN_init_thread();
  void *ret = wa->start_routine(wa->arg);
  free(wrapped_arg);
  return ret;
}

