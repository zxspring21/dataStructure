#include <iostream>
#include <cstdlib>
#include "array.h"

template<class ElemType, int kNumOfElems>
std::ostream &operator<<(std::ostream &lhs, 
                         const Array<ElemType, kNumOfElems> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
} 


int main() {
  using std::cout;
  using std::endl;

  Array<int, 10> a;
  for (int i = 0; i < a.Size(); ++i) {
    a[i] = i;
  }
 
  int * const begin = &a[0];
  int * const end   = &a[10];
  for (int *p = begin; p != end; ++p) {
    cout << *p << endl;
  }

  system("pause");
  return 0; 
}
