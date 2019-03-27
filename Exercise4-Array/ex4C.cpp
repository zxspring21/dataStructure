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

  // 實作切割建構式
  IntArray(const IntArray &x, int begin, int end); 

  ~IntArray() {
    delete [] data_;
  }

  int Size() const { return size_; } 

  // 實作切割函式
  const IntArray Slice(int begin, int end) const; 

  int &At(int i)              { return data_[i]; }
  int At(int i) const         { return data_[i]; } 
  int &operator[](int i)      { return At(i); }  
  int operator[](int i) const { return At(i); }  

  const IntArray &operator=(const IntArray &rhs) {
    if (this != &rhs) {
      delete [] data_;
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

IntArray::IntArray(const IntArray &x, int begin, int end) {
  /* TODO */
}

const IntArray IntArray::Slice(int begin, int end) const {
  /* TODO */
}

std::ostream &operator<<(std::ostream &lhs, const IntArray &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << ' ';
    lhs << rhs[i];
  }
  return lhs;
} 

int main() {
  using namespace std;

  IntArray a(5);
  for (int i = 0; i < 5; ++i) { a[i] = i; }
  cout << "a: " << a << endl;

  IntArray b(a, 1, 4), c(a, 0, 5);
  cout << "b: " << b << endl
       << "c: " << c << endl;

  cout << "a.Slice(3, 5): " << a.Slice(3, 5) << endl
       << "a.Slice(1, 3): " << a.Slice(1, 3) << endl; 

  system("pause");
  return 0;
}
