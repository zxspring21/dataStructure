#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
std::ostream &operator<<(std::ostream &lhs, const std::vector<T> &rhs) {
  for (int i = 0; i < rhs.size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using namespace std;
  vector<int> a(5);
  vector<double> b(5);
  for (int i = 0; i < 5; ++i) {
    a[i] = 1.1*i;
    b[i] = 1.1*i;
  }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  vector<int> c;
  for (int i = 0; i < 5; i++) {
    c.push_back(i);
  }
  cout << "c: " << c << endl;

  for (int i = 0; i < 3; i++) {
    c.pop_back();
  }
  cout << "c: " << c << endl;

  system("pause");
  return 0; 
}
