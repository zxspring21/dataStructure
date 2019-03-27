#include <iostream>
#include <cstdlib>
#include <string>

int main() {
  using namespace std;
  string a = "Hello";
  string b = "world";
  cout << a + " " + b + "!" << endl;
  
  cout << "a: ";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
  }
  cout << endl; 
  system("pause");
  return 0;
}
