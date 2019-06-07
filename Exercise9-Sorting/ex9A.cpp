#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct LargerThan {
 inline bool operator()(int a, int b) const {
  // TODO
  return a>b;
 }
};

ostream &operator<<(ostream &lhs, const vector<int> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  vector<int> a(10);
  for (size_t i = 0; i < a.size(); ++i) {
    a[i] = rand() % 30;
  }
  cout << "a: " << a << endl;
  sort(a.begin(), a.end());
  cout << "a: " << a << endl;

  for (size_t i = 0; i < a.size(); ++i) {
    a[i] = rand() % 30;
  }
  cout << "a: " << a << endl;
  sort(a.begin(), a.end(), LargerThan());
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
