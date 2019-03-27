#include <iostream>
#include <cstdlib>

typedef int Array[20];

std::ostream &operator<<(std::ostream &lhs, const Array &rhs) {
  for (int i = 0; i < 20; ++i) {
    if (i > 0) {
      lhs << ' ';
    }
    lhs << rhs[i];
  }
  return lhs;
}
int main() {
  using namespace std;
  int a = 5;
  cout << "a: " << a << endl;

  typedef int Grade;
  Grade b = 5;
  cout << "b: " << b << endl; 

  Array c;
  Array d;

  for (int i = 0; i < 20; ++i) {
    c[i] = i;
  }
  cout << "c: " << c << endl;
  return 0;
}
