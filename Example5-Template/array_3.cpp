#include <iostream>
#include <cstdlib>

template<typename ElemType, int kNumOfElems>
class Array {
 public:
  static int Size()               { return kNumOfElems; } 
  ElemType &At(int i)             { return data_[i]; }
  const ElemType &At(int i) const { return data_[i]; } 

  ElemType &operator[](int i)             { return At(i); }  
  const ElemType &operator[](int i) const { return At(i); }  

 private:
  ElemType data_[kNumOfElems];
};

template<typename ElemType, int kNumOfElems>
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

  Array<double, 10> a;
  Array<int, 10>    b;

  for (int i = 0; i < a.Size(); ++i) a[i] = 1.1 * i;
  cout << "a: " << a << endl;

  for (int i = 0; i < b.Size(); ++i) b[i] = 1.1 * i;
  cout << "b: " << b << endl;

  system("pause");
  return 0; 
}
