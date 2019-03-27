#include <iostream>
#include <cstdlib>

template<typename T>
class Grade {
 public:
  Grade()              { data_ = 0; }
  Grade(const T &v)    { data_ = v; }
  void Set(const T &v) { data_ = v; }
  const T &Get() const { return data_; }
  const Grade<T> operator+(const Grade<T> &rhs) const {
    return Grade(this->Get() + rhs.Get());
  }

 private:
  T data_;
};

template<typename T>
std::ostream &operator<<(std::ostream &lhs, const Grade<T> &rhs) {
  lhs << rhs.Get();
  return lhs;
}
 
int main() {
  using namespace std;
  Grade<int> a = 30.5, b = 20.5;
  cout << "a: " << a << ", b: " << b << endl;
  cout << "a + b == " << a + b << endl;
 
  Grade<double> c = 30.5, d = 20.5;
  cout << "c: " << c << ", d: " << d << endl;
  cout << "c + d == " << c + d << endl;

  cout << a + c << endl;              // [編譯錯誤] 請將此行移除 
  system("pause");
  return 0;
}
