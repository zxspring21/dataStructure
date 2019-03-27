#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

ostream &operator<<(ostream &lhs, const list<int> &rhs) {
  for (list<int>::const_iterator i = rhs.begin();
       i != rhs.end(); ++i) {
    if (i != rhs.begin()) lhs << " ";
    lhs << *i;
  }
  return lhs;
}

template <class Iterator, class Type>
Iterator binary_search(
    Iterator first, Iterator last,  const Type &val) {
  int dist = distance(first, last);
  if (dist == 0) return last;
  Iterator mid;
  while (dist > 0) {
    int step = dist / 2;
    mid = first;
    advance(mid, step);
    if (*mid < val ) {
      first = ++mid;
      dist = dist - step - 1;
    } else {
      dist = step;
    }
  }
  if (*first != val) return last;
  return first;
}
 
int main() {
  list<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%10);
  cout << "a: " << a << endl;
  a.sort();
  cout << "a: " << a << endl;
  *binary_search(a.begin(), a.end(), 4) = 10;
  cout << "a: " << a << endl;
  a.sort();
  list<int>::iterator p = binary_search(a.begin(), a.end(), 4);
  while (p != a.end()) {
    *p = 10;
    a.sort();
    p = binary_search(a.begin(), a.end(), 4);
  }
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}


