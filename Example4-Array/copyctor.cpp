#include <iostream>
#include <cstdlib> 
using namespace std;

class Grade {
 public:
  Grade() {
    cout << "call Grade() " << endl; 
    data_ = 0;
  }
  Grade(int v) {
    cout << "call Grade(int) " << endl;
    data_ = v;
  }
  Grade(const Grade& rhs) {
    cout << "call Grade(const Grade &) " << endl;
    data_ = rhs.data_;
  }
  int Get() const { return data_; }
  void Set(int v) { data_ = v; }
 private:
  int data_;
};

ostream &operator<<(ostream &lhs, const Grade &rhs) {
  lhs << rhs.Get();
  return lhs;
}

int main() {
  Grade a(30);
  Grade b(a);
  Grade c = b;
  cout << "a: " << a << endl
       << "b: " << b << endl
       << "c: " << c << endl;
  system("pause");
  return 0;
}
