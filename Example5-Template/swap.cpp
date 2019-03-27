#include <iostream>
#include <cstdlib>

template<typename T>
void Swap(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}

class Grade {
 public:
  Grade()         { data_ = 0; }
  Grade(int v)    { data_ = v; }
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }
 private:
  int data_;
};

std::ostream &operator<<(std::ostream &lhs, const Grade &rhs) {
  lhs << rhs.Get();
  return lhs;
}
 
int main() {
  using namespace std;
  int a = 3, b = 5;
  cout << "a: " << a << ", b: " << b << endl;
  Swap<int>(a, b);
  cout << "a: " << a << ", b: " << b << endl;
   
  double c = 3.3, d = 5.5;
  cout << "c: " << c << ", d: " << d << endl;
  Swap<double>(c, d);
  cout << "c: " << c << ", d: " << d << endl;

  Grade e = 3, f = 5;
  cout << "e: " << e << ", f: " << f << endl;
  Swap<Grade>(e, f);
  cout << "e: " << e << ", f: " << f << endl;

  int g = 3, h = 5;
  cout << "g: " << g << ", h: " << h << endl;
  Swap(g, h); // 可以自動從函式參數直接判斷時, 模板參數時可省略 
  cout << "g: " << g << ", h: " << h << endl;

  system("pause");
  return 0;
}
