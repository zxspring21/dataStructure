#include <stdio.h>
#include <stdlib.h>

class ConsoleOut {
};

const ConsoleOut &operator<<(const ConsoleOut &lhs, float rhs) {
  /* TODO */
  printf("%f",rhs);
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, double rhs) {
  /* TODO */
  printf("%lf",rhs);
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, int rhs) {
  /* TODO */ 
  printf("%d",rhs);
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, char rhs) {
  /* TODO */
  printf("%c",rhs);
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, const char *rhs) {
  /* TODO */
  while(*rhs!='\0'){
     printf("%c",*rhs);
     rhs++;
  }
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
