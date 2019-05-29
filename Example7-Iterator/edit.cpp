#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
using namespace std;

template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType> &rhs) {
  for (typename vector<ElemType>::const_iterator p = rhs.begin(); 
       p != rhs.end(); ++p) {
    if (p != rhs.begin()) lhs << " ";
    lhs << *p;
  }
  return lhs;
}

template<class ElemType>
ostream &operator<<(ostream &lhs, const list<ElemType> &rhs) {
  for (typename list<ElemType>::const_iterator p = rhs.begin(); 
       p != rhs.end(); ++p) {
    if (p != rhs.begin()) lhs << " ";
    lhs << *p;
  }
  return lhs;
}

int main() {
  vector<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%10);
  cout << "a: " << a << endl;
  
  a.insert(a.begin()+5, 10);
  cout << "a: " << a << endl;
  
  a.erase(a.begin()+5);
  cout << "a: " << a << endl;

  list<int> b(a.begin(), a.end()); // 利用迭代器的建構式 
  cout << "b: " << b << endl;
  list<int>::iterator p = b.begin();
    
  advance(p, 5);             // 移動迭代器的函式
  b.insert(p, 10);
  
  cout << "b: " << b << endl;
  
  b.erase(p);                // 刪除的是哪一個?
  
  cout << "b: " << b << endl;
  system("pause");
  return 0;
}
