#ifndef H_ARRAY_
#define H_ARRAY_

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
  typedef ArrayIterator<const ElemType> ConstIterator;
  typedef ElemType ValueType; 

  static int Size() { return kNumOfElems; } 
  ElemType &At(int i)             { return data_[i]; }
  const ElemType &At(int i) const { return data_[i]; } 
  Iterator Begin()            { return data_; }
  ConstIterator Begin() const { return data_; }
  Iterator End()              { return data_ + kNumOfElems; } 
  ConstIterator End()   const { return data_ + kNumOfElems; } 
  ElemType &operator[](int i)             { return At(i); }  
  const ElemType &operator[](int i) const { return At(i); }  

 private:
  ElemType data_[kNumOfElems];
};
#endif // H_ARRAY_
