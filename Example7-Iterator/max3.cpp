#include <iostream>
#include <cstdlib>
#include "flist.h"
#include "array.h"

template<class ContainerType>
const typename ContainerType::ValueType Max(const ContainerType &c) {
  typename ContainerType::ConstIterator max_iter = c.Begin();
  for (typename ContainerType::ConstIterator p = c.Begin(); p != c.End(); ++p) {
    if (*p > *max_iter) {
      max_iter = p;
    }
  }
  return *max_iter; 
}

template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const ForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}


template<class ElemType, int kNumberOfElems>
std::ostream &operator<<(std::ostream &lhs, const Array<ElemType, kNumberOfElems> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;

  Array<int, 10> a;
  ForwardList<int> b(10); 

  for (int i = 0; i < 10; ++i) {
    const int r = rand();
    a[i] = b[i] = r;    
  }

  cout << "a: " << a << endl
       << "b: " << b << endl;

  cout << "Max(a): " << Max(a) << endl;    
  cout << "Max(b): " << Max(b) << endl; 

  return 0;
} 
