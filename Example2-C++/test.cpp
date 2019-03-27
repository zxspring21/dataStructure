#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Grade {
 public:
  void Set(int v) {
    if(v>100) 
	data_ = 100;
    else if(v<0) 
	data_ = 0;
    else 
    	data_ = v;
  }
  int Get() {
    return data_;
  }

 private:
  int data_;
}; 

int main() {
  Grade a;
  a.Set(50);
  printf("a: %d\n", a.Get());

  Grade b;
  b.Set(-50);
  printf("b: %d\n", b.Get());

  Grade c;
  c.Set(150);
  printf("c: %d\n", c.Get());
  system("pause");
  return 0;
} 
