#include <iostream>
#include <cstdlib>

class Grade {
 public:
  Grade()         { data_ = 0; }
  Grade(int v)    { this->Set(v); }
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }
  bool operator>(const Grade &rhs) {
    return this->Get() > rhs.Get();
  }

 private:
  int data_;
};


// 把下面這個 Max 函式變成一個模板函式來處理各種資料類型 

template<typename T>
T Max(T a, T b, T c) {
  T ret = a;
  if (b > ret) ret = b;
  if (c > ret) ret = c;
  return ret;
}

std::ostream &operator<<(std::ostream &lhs, const Grade &rhs) {
  lhs << rhs.Get();
  return lhs;
}
 

int main() {
  using namespace std;
  Grade a = 5, b = 4, c = 3;
  cout << "Max(3, 5, 4)      : " << Max(3, 5, 4)       << endl
       << "Max(3.5, 4.5, 5.5): " << Max(3.5, 4.5, 5.5) << endl 
       << "Max(a, b, c)      : " << Max(a, b, c)       << endl; 
  system("pause");
  return 0; 
}
