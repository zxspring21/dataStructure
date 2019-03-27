#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  // 新增了解構式 
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
 private:
  int size_;
  int *data_;
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "陣列 a 的大小為: " << a.Size() << endl;
  a[3] = 7;
  cout << "陣列 a 的第三號元素為: " << a[3] << endl;

  const IntArray &d = a;
  cout << "陣列 d 的大小為: " << d.Size() << endl;  
  cout << "陣列 d 的第三號元素為: " << d[3] << endl; 
  system("pause");
  return 0; 
}
