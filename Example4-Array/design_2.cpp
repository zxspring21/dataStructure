#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n);
  int Size() const;    
  int &At(int i);
  int At(int i) const;
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "陣列 a 的大小為: " << a.Size() << endl;
  a.At(3) = 7;
  cout << "陣列 a 的第三號元素為: " << a.At(3) << endl;

  IntArray b = 5;     // [編譯錯誤] 請移除此行 
  IntArray c;         // [編譯錯誤] 請移除此行 

  const IntArray &d = a;
  cout << "陣列 d 的大小為: " << d.Size() << endl;  
  cout << "陣列 d 的第三號元素為: " << d.At(3) << endl; 
  system("pause");
  return 0; 
}
