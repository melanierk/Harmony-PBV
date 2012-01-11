#include <stdio.h>

extern void foo1();
extern void foo4();

void foo2() {
  printf("Foo2\n");
}

void foo3() {
  foo4();
}

int main() {
  foo1();
}

