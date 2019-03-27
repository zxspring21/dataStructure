#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  IntArray(const IntArray &rhs) {
    size_ = rhs.size_;
    data_ = new int[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  }
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  ~IntArray() {
    delete[] data_;
  }
  int Size() const {
    return size_;
  }    
  int &At(int i) {
    return data_[i];
  }
  int At(int i) const {
    return data_[i];
  }
  int &operator[](int i) {
    return At(i);
  }
  int operator[](int i) const {
    return At(i);
  }
  IntArray &operator=(const IntArray &rhs) {
    if (this != &rhs) {
      delete[] data_;
      size_ = rhs.size_;
      data_ = new int[rhs.size_];
      for (int i = 0; i < rhs.size_; ++i) {
        data_[i] = rhs.data_[i];
      }
    }
    return *this;
  }
 private:
  int size_;
  int *data_;
};

std::ostream &operator<<(std::ostream &lhs, const IntArray &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << ' ';
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using namespace std;
  IntArray a(10);
  for (int i = 0; i < a.Size(); ++i) {
    a[i] = i;
  }
  cout << "a: " << a << endl;

  IntArray b = a;
  b[0] = 10;
  cout << "a: " << a << endl
       << "b: " << b << endl;

  IntArray c(5);
  for (int i = 0; i < 5; ++i) {
    c[i] = 11 + i;
  }

  cout << "c: " << c << endl;
 
  c = a;
  c[9] = 15; 
  cout << "a: " << a << endl
       << "c: " << c << endl;

  a = a;
  cout << "a: " << a << endl; 
  system("pause");
  return 0; 
}
