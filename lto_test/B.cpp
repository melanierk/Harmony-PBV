#include <cstdio>

struct B {
  int i;
  B() { 
    i = 0;
    puts("In the constructor");
  }
};

B globalB;

int main() {
  return 0;
}

extern "C" void PROF_IN_init_module() {
  puts("In PROF_IN_init_module");
}

