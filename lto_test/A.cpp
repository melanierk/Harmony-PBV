#include <iostream>
#include <string>

using namespace std;

string str = "Hello!\n";

extern void foo();

void bar() {
  cout << str;
}

int main() {
  foo();
}

