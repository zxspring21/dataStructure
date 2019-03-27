#include <stdio.h>
#include <stdlib.h>

class ConsoleOut {
};

const ConsoleOut &operator<<(const ConsoleOut &lhs, float rhs) {
  /* TODO */
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, double rhs) {
  /* TODO */
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, int rhs) {
  /* TODO */ 
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, char rhs) {
  /* TODO */
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, const char *rhs) {
  /* TODO */
  return lhs;
} 

int main() {
  ConsoleOut cout;
  cout << 3.f << '\n' 
       << 3. << '\n' 
       << 3 << '\n';

  cout << "Hello world!\n";
  system("pause");
  return 0;
} 
