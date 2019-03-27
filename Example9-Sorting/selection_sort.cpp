#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;

template<class ElemType>
void SelectionSort(vector<ElemType> &x) {
  for (int i = 0; i < static_cast<signed>(x.size())-1; ++i) {
    int min_j = i;
    for (size_t j = i+1; j < x.size(); ++j) {
      if (x[j] < x[min_j]) min_j = j;
    }
    swap(x[i], x[min_j]); 
  }
}

template<class Container>
void GenericSelectionSort(Container &x) {
  for (typename Container::iterator i = x.begin();
       i != x.end(); ++i) {
    typename Container::iterator min_j = i;
    typename Container::iterator j = i;
    ++j;
    while (j != x.end()) {
      if (*j < *min_j) min_j = j;
      ++j;
    }
    swap(*i, *min_j); 
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
  SelectionSort(a);
  cout << "a: " << a << endl; 

  vector<int> b(10);
  for (size_t i = 0; i < b.size(); ++i) b[i] = rand() % b.size();
  cout << "b: " << b << endl;
  GenericSelectionSort(b);
  cout << "b: " << b << endl; 

  list<int> c(10);
  for (list<int>::iterator i = c.begin(); i != c.end(); ++i) {
    *i = rand() % c.size();
  }  
  cout << "c: " << c << endl;
  GenericSelectionSort(c);
  cout << "c: " << c << endl; 

  system("pause");
  return 0;
} 
