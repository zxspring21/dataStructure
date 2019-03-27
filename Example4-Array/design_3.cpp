#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n);
  int Size() const;    
  int &At(int i);
  int At(int i) const;
  int &operator[](int i);
  int operator[](int i) const;
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "陣列 a 的大小為: " << a.Size() << endl;
  a[3] = 7;
  cout << "陣列 a 的第三號元素為: " << a[3] << endl;

  const IntArray &d = a;
  cout << "陣列 d 的大小為: " << d.Size() << endl;  
  cout << "陣列 d 的第三號元素為: " << d[3] << endl; 
  system("pause");
  return 0; 
}
