#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  vector<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%30);

  priority_queue<int> q(a.begin(), a.end());

  cout << "q: ";
  for (int i = 1; i <= 10; ++i) {
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;

  cout << "a: " << a << endl;
  make_heap(a.begin(), a.end());
  cout << "a: " << a << endl;
  sort_heap(a.begin(), a.end());
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
