#include <iostream>
#include <cstdlib>
#include <map>
 
using namespace std;

int main() {
  map<string, int> q;
  q["Chang"] = 1;
  q["Huang"] = 2;
  q["Hung"]  = 3;
  q["Lee"]   = 4;
  q["Wang"]  = 5;
  
  string cand[3] = {"Chang", "Lee", "Kuo"};
  for (int i = 0; i < 3; ++i) { 
    if (q.find(cand[i]) != q.end()) {
      cout << cand[i] << ": " << q[cand[i]] << endl; 
    } else {
      cout << cand[i] << " 找不到" << endl;
    } 
  } 
  system("pause");
  return 0;
}
