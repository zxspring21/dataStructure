#include <iostream>
#include <cstdlib>

class Grade {
 public:
  Grade() {
    std::cout << "\t產生一個 Grade 物件並將值歸零" << std::endl; 
    data_ = 0;
  } 
  
  Grade(int v) {
    std::cout << "\t產生一個 Grade 物件並將值設為 " << v << std::endl;
    data_ = v; 
  }

  ~Grade() {
    std::cout << "\t釋放一個 Grade 物件" << std::endl;
  }
 
 private:
  int data_;
};

int main() {
  std::cout << "一次配置一個物件:" << std::endl;
  Grade *a = new Grade;
  Grade *b = new Grade();
  Grade *c = new Grade(3);
  delete a;
  delete b;
  delete c;

  std::cout << std::endl
            << "配置陣列:" << std::endl;
  Grade *d = new Grade[3];
  delete [] d; // 試試看將 [] 移除的差別 

  std::system("pause");
  return 0;
} 
