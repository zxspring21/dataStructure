#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

ostream &operator<<(ostream &lhs, const vector<int> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

struct MyComp {
  inline bool operator()(int a, int b) {
    // TODO
     
    
    return a%2?a<b:a>b;
  }
};
 
int main() {
  vector<int> a;
  for (int i = 0; i < 10; ++i) {
    a.push_back(rand()%9);
  } 
  cout << "a: " << a << endl; 

  sort(a.begin(), a.end(), MyComp());
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
