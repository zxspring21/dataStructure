#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  IntArray(int n);
  int Size();    
  int At(int i);
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "陣列 a 的大小為: " << a.Size() << endl;
  a.At(3) = 7;        // [編譯錯誤] 
  cout << "陣列 a 的第三號元素為: " << a.At(3) << endl;

  IntArray b = 6;     // 這是甚麼意思 ? 
  IntArray c;         // [編譯錯誤] 

  const IntArray d = a;
  cout << "陣列 d 的大小為: " << d.Size() << endl;      // [編譯錯誤] 
  cout << "陣列 d 的第三號元素為: " << d.At(3) << endl; // [編譯錯誤] 
  system("pause");
  return 0; 
}
