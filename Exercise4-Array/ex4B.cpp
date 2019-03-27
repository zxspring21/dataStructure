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
    delete [] data_;
  }

  int Size() const { return size_; } 

  // 新增下列兩個函式 
  void Swap(IntArray &x);
  void Reverse();

  int &At(int i)              { return data_[i]; }
  int At(int i) const         { return data_[i]; }
  int &operator[](int i)      { return At(i); }
  int operator[](int i) const { return At(i); }

 private:
  int size_;
  int *data_;
};

// 我們可以將成員函式定義在類別宣告外, 此時函式名稱的全名是 "類別名稱::成員函式名稱" 
void IntArray::Swap(IntArray &x) {
  /* TODO */
}

void IntArray::Reverse() {
  /* TODO */
}

ostream &operator<<(ostream &lhs, const IntArray &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
} 

int main() {
  IntArray a(5);
  for (int i = 0; i < 5; ++i) a[i] = i;
  cout << "a: " << a << endl;

  IntArray b(8);
  for (int i = 0; i < 8; ++i) b[i] = i+5;
  cout << "b: " << b << endl;

  IntArray c = a;
  c.Reverse();
  cout << "c: " << c << endl;
  c.Reverse();
  cout << "c: " << c << endl;

  b.Reverse();
  cout << "b: " << b << endl;
  b.Reverse();
  cout << "b: " << b << endl;
  
  a.Swap(b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl; 


  a.Swap(b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl; 
  system("pause");
  return 0;
}
