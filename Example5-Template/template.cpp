#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
void Set(T &x, T v) {
  cout << "呼叫 template<typename T> Set(T &x, T v);" << endl; 
  x = v;
}

void Set(int &x, int v) {
  cout << "呼叫 Set(int &x, int &v);" << endl; 
  x = v;
}

void Set(double &x, double v) {
  cout << "呼叫 Set(double &x, double &v);" << endl; 
  x = v;
}

int main() {
  int a = 3;
  double b = 3.5;

  cout << "a: " << a << endl
       << "b: " << b << endl;

  // 以下是函式多載:
  Set(a, 5);       // Set(int &x, int v);
  Set(b, 5.5);     // Set(double &x, double v);

  cout << "a: " << a << endl
       << "b: " << b << endl;

  Set(a, 7.5);     // Set(int &x, int v);
  Set(b, 7);       // Set(double &x, double v); 

  cout << "a: " << a << endl
       << "b: " << b << endl;

  // 以下是使用函式模版:
  Set<int>(a, 5);        // template<typename T = int>    Set(T &x, T v);
  Set<double>(b, 5.5);   // template<typename T = double> Set(T &x, T v); 

  cout << "a: " << a << endl
       << "b: " << b << endl;

  system("pause");
  return 0;
}
