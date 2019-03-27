#include <iostream>
#include <cstdlib>

// 新增迭代器類別 
template<class ElemType>
class ArrayIterator {
 public:
  ArrayIterator(ElemType *p) {
    p_ = p;
  }
  ArrayIterator<ElemType> &operator++() {
    ++p_;
    return *this;
  }
  ArrayIterator<ElemType> operator++(int) {
    ArrayIterator<ElemType> ret = *this;
    ++p_;
    return ret;
  }
  bool operator!=(const ArrayIterator<ElemType> &rhs) {
    return p_ != rhs.p_;
  }
  bool operator==(const ArrayIterator<ElemType> &rhs) {
    return p_ == rhs.p_;
  }
  ElemType &operator*() {
    return *p_;
  }
  ElemType *operator->() {
    return p_;
  }

 private: 
  ElemType *p_;
};

template<class ElemType, int kNumOfElems>
class Array {
 public:
  typedef ArrayIterator<ElemType> Iterator;

  static int Size() { return kNumOfElems; } 
  ElemType &At(int i)             { return data_[i]; }
  const ElemType &At(int i) const { return data_[i]; } 
  // 新增下列兩個函式:
  Iterator Begin() { return &data_[0]; }
  Iterator End()   { return &data_[10]; }
 
  ElemType &operator[](int i)             { return At(i); }  
  const ElemType &operator[](int i) const { return At(i); }  

 private:
  ElemType data_[kNumOfElems];
};

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

  const ArrayIterator<int> begin = a.Begin();
  const ArrayIterator<int> end   = a.End();
  for (ArrayIterator<int> p = begin; p != end; ++p) {
    cout << *p << endl;
  }

  system("pause");
  return 0; 
}
