#include <pthread.h>
#include <stdio.h>

void f() {
  printf("FFF\n");
}

void g() {
  printf("GGG\n");
}

void h() {
  printf("HHH\n");
}

typedef void (*ptr_f_t)();

ptr_f_t start_routines[5] = { f, g, h, h, f };

int main() {
  pthread_t threads[5];
  for (int i = 0; i < 5; i++) {
    pthread_create(threads + i, NULL, start_routines[i], NULL);
  }
  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
