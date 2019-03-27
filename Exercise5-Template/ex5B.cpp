#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

class IntVector {
 public:
  IntVector() {
    size_ = 0;
    data_ = NULL;
  }
  IntVector(const IntVector &rhs) {
    size_ = rhs.size_;
    data_ = new int[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  } 
  explicit IntVector(int n) {
    size_ = n;
    data_ = new int[n];
  } 
  ~IntVector() { delete[] data_; } 
  int Size() const { return size_; } 
  void Resize(int n) {
    int *new_data = new int[n];
    for (int i = 0; i < size_ && i < n; ++i) { 
      new_data[i] = data_[i];
    }
    delete [] data_;
    data_ = new_data;
    size_ = n;
  } 

  int &At(int i)              { return data_[i]; }
  int At(int i) const         { return data_[i]; }
  int &operator[](int i)      { return At(i); }  
  int operator[](int i) const { return At(i); }  

 private:
  int size_;
  int *data_;
};


std::ostream &operator<<(std::ostream &lhs, const IntVector &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}


// 參照上方的 IntVector 類別來製作 Vector 模板 
template<typename ElemType>
class Vector {
 /* TODO */ 
};


template<typename ElemType>
std::ostream &operator<<(std::ostream &lhs, const Vector<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using namespace std;
  Vector<int> a(5);
  Vector<double> b(5);
  for (int i = 0; i < 5; ++i) {
    a[i] = 1.1*i;
    b[i] = 1.1*i;
  }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  Vector<int> c = a;
  cout << "c: " << c << endl;

  Vector<double>
  d = b;
  cout << "d: " << d << endl; 

  a.Resize(1);
  b.Resize(1); 
  cout << "a: " << a << endl
       << "b: " << b << endl;

  system("pause");
  return 0; 
}
