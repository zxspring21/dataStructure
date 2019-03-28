#include <stdio.h>
#include <stdlib.h>

class Grade {
 public:
  Grade()         { data_ = 0;} 
  Grade(int v)    { data_ = v; }

  void Set(int v) { data_ = v; }
  int Get() const { return data_; }

 private:
  int data_;
};

const Grade Add(const Grade &lhs, const Grade &rhs) {
  printf("ok");
  return lhs.Get() + rhs.Get(); 
}

const Grade operator+(const Grade &lhs, const Grade &rhs) {
  printf("in\n");
  return Add(lhs, rhs);  // 或者 return lhs.Get() + rhs.Get(); 也可 
}

int main() {
  Grade a = 10;
  Grade b = 20;
  Grade c = Add(a, b);
 printf("c\n");
  Grade d = a + b;
printf("d\n");
  printf("a: %d\n"
         "b: %d\n"
         "c: %d\n"
         "d: %d\n", a.Get(), b.Get(), c.Get(), d.Get());
printf("---");
  system("pause");
  return 0;
} 
