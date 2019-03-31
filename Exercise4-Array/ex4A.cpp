#include <iostream>
#include <cstdlib>

using namespace std;

class IntArray {
 public:
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  ~IntArray() {
    delete[] data_;
  }
  int Size() const { return size_; } 

  // 實作下列函式 
  int &Front()      { return data_[0]; }
  int Front() const { return data_[0];  }
  int &Back()       { return data_[size_-1]; }
  int Back() const  { return data_[size_-1]; }

  int &At(int i)              { return data_[i]; }
  int At(int i) const         { return data_[i]; } 
  int &operator[](int i)      { return At(i);    }  
  int operator[](int i) const { return At(i);    }  

 private:
  int size_;
  int *data_;
};

ostream &operator<<(ostream &lhs, const IntArray &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
} 

int main() {
  IntArray a(5);
  for (int i = 0; i < 5; ++i) {
    a[i] = i;
  }
  cout << "a: " << a << endl;

  a.Front() = 10;
  a.Back() = 11;
  cout << "a: " << a << endl;

  const IntArray &b = a;
  cout << "b.Front(): " << b.Front() << endl
       << "b.Back() : " << b.Back()  << endl;


  IntArray c(3);
  for (int i = 0; i < 3; ++i) {
    c[i] = i + 12;
  }
  cout << "c: " << c << endl;

  c.Front() = 15;
  c.Back() = 16;
  cout << "c: " << c << endl;

  const IntArray &d = c;
  cout << "d.Front(): " << d.Front() << endl
       << "d.Back() : " << d.Back()  << endl;

  system("pause");
  return 0;
}
