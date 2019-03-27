#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>

using namespace std;
class Grade {
 public:
  Grade() { data_ = 0; }
  Grade(int v) { data_ = v; }
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }
  // 提供 operator< 
  bool operator<(const Grade &rhs) const {
    return this->Get() < rhs.Get();
  }

 private:
  int data_;
};

ostream &operator<<(ostream &lhs, const vector<Grade> &rhs) {
  for (vector<Grade>::const_iterator p = rhs.begin(); p != rhs.end(); ++p) {
    if (p != rhs.begin()) lhs << " ";
    lhs << p->Get();
  }
  return lhs;
}

ostream &operator<<(ostream &lhs, const list<Grade> &rhs) {
  for (list<Grade>::const_iterator p = rhs.begin(); p != rhs.end(); ++p) {
    if (p != rhs.begin()) lhs << " ";
    lhs << p->Get();
  }
  return lhs;
}

// 提供比較函式 
bool Comp1(const Grade &a, const Grade &b) {
  return a.Get() < b.Get();
} 

// 提供比較類別 
struct Comp2 {
  inline bool operator()(const Grade &a, const Grade &b) {
    return a.Get() < b.Get();
  }
};

int main() {
  vector<Grade> a(10);
  for (size_t i = 0; i < a.size(); ++i) {
    a[i] = rand() % 100;
  }
  vector<Grade> b = a;
  vector<Grade> c = a;
  list<Grade> d(a.begin(), a.end());
  list<Grade> e = d;
  list<Grade> f = d;

  // 使用多載類別的 operator< 
  cout << a << endl;
  sort(a.begin(), a.end());
  cout << a << endl;

  // 使用自訂函式指標 (function pointer) 
  sort (b.begin(), b.end(), Comp1); 
  cout << b << endl;

  // 使用自訂函式物件 (function object) 
  sort (c.begin(), c.end(), Comp2()); 
  cout << c << endl;

  // sort(d.begin(), d.end()); // [編譯錯誤]
 
  // 使用 list 內建的 sort
  d.sort();
  cout << d << endl; 
  
  e.sort(Comp1);
  cout << e << endl;
  
  f.sort(Comp2());
  cout << f << endl; 
  system("pause");
  return 0;
}
