#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

template<class ElemType>
void InsertionSort(vector<ElemType> &x) {
  for (size_t i = 1; i < x.size(); ++i) {
    ElemType t = x[i];
    int j = i-1;
    while (j >= 0 && x[j] > t) {
      x[j+1] = x[j];
      --j;
    }
    x[j+1] = t;
  }
}


template<class ElemType>
void InsertionSort(list<ElemType> &x) {
  typedef typename list<ElemType>::iterator Iterator;
  Iterator i = x.begin();
  ++i;
  while (i != x.end()) {
    Iterator j = x.begin();
    while (j != i && *j < *i) ++j;
    x.insert(j, *i);
    Iterator k = i;
    ++i;
    x.erase(k);
  }
}


template<class Container>
void GenericInsertionSort(Container &x) {
  typedef typename Container::iterator Iterator;
  Iterator i = x.begin();
  ++i;
  while (i != x.end()) {
    typename Container::value_type t = *i;
    Iterator j = i;
    j--;
    Iterator k = i;
    while (t < *j && k != j) {
      *k = *j;
      if (j == x.begin()) {
        k = j;
      } else {
        --j;
        --k;
      }
    }
    *k = t;
    ++i;
  }
}


template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
} 

template<class ElemType>
ostream &operator<<(ostream &lhs, const list<ElemType> &rhs) {
  for (typename list<ElemType>::const_iterator i = rhs.begin(); 
       i != rhs.end(); ++i) {
    if (i != rhs.begin()) lhs << " ";
    lhs << *i;
  }
  return lhs;
} 

int main() {
  vector<int> a(10);
  for (size_t i = 0; i < a.size(); ++i) a[i] = rand() % a.size();
  cout << "a: " << a << endl;
  InsertionSort(a);
  cout << "a: " << a << endl; 

  vector<int> b(10);
  for (size_t i = 0; i < b.size(); ++i) b[i] = rand() % b.size();
  cout << "b: " << b << endl;
  GenericInsertionSort(b);
  cout << "b: " << b << endl; 

  list<int> c(10);
  for (list<int>::iterator i = c.begin(); i != c.end(); ++i) {
    *i = rand() % c.size();
  }  
  cout << "c: " << c << endl;
  InsertionSort(c);
  cout << "c: " << c << endl; 

  list<int> d(10);
  for (list<int>::iterator i = d.begin(); i != d.end(); ++i) {
    *i = rand() % d.size();
  }  
  cout << "d: " << d << endl;
  GenericInsertionSort(d);
  cout << "d: " << d << endl; 

  system("pause");
  return 0;
} 
