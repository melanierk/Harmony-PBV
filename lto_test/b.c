#include <stdio.h>

extern void foo2();

void foo1() {
  foo2();
}

void foo4() {
  printf("Foo4");
}

