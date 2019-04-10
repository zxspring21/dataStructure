#include <iostream>
using namespace std;

class Grade {
 public:
  Grade() {
    cout << "呼叫 Grade() " << endl; 
    data_ = 0;
  }
  Grade(int v) {
    cout << "呼叫 Grade(int) " << endl;
    data_ = v;
  }
  Grade(const Grade& rhs) {
    cout << "呼叫 Grade(const Grade &) " << endl;
    data_ = rhs.data_;
  }
  Grade &operator=(const Grade &rhs) {
    cout << "呼叫 Grade::operator=(const Grade&) " << endl;
    data_ = rhs.data_;
    return *this; // 賦值運算的回傳值形態一般為第一個運算元型態, 在成員函式內其值為 *this
    // 寫 b = a 會呼叫 b.operator=(a), 而此時 this 是 &b 且 *this 就是 b  
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
  cout << "[Case 1]" << endl;
  cout << "Grade a(30), b , c"<< endl;
  Grade a(30), b, c;
  cout << "a: " << a << endl;
  cout << endl;

  cout << "[Case 2]" << endl;
  cout << "b = a " << endl;
  b = a;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << endl;

  
  cout << "[Case 3]" << endl;
  cout <<" b = 50"<<endl;
  b = 50;
  cout << "b: " << b << endl;
  cout << endl;

  cout << "[Case 4]" << endl;
  cout <<" c = a = 30"<<endl;
  c = a = 30;
  cout << "a: " << a << endl;
  cout << "c: " << c << endl;
  cout << endl;

  cout << "[Case 5]" << endl;
  cout << "( c = 20) = b"<<endl;
  (c = 20) = b;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << endl;

  cout << "[Case 6]" << endl;
  cout << "Grade d = c = b:"<<endl;
  Grade d = c = b;
  cout << endl;
  return 0;
}
