#include <stdio.h>

void PROF_IN_init_module() {
  fprintf(stderr, "** called PROF_IN_init_module **\n");
}

void PROF_IN_init_thread() {
  fprintf(stderr, "** called PROF_IN_init_thread **\n");
}
