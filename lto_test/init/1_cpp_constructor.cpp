#include <pthread.h>
#include <iostream>
#include <string>
using namespace std;

string msg = "Hello";

void *f(void *p) {
  cout << msg << endl;
  return NULL;
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(threads + i, NULL, f, NULL);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
