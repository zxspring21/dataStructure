#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  list<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%20);

  const list<int> b = a;                  
  cout << "b: ";
  for (list<int>::const_iterator p = b.begin(); 
       p != b.end(); ++p) {
    if (p != a.begin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  cout << "b~: ";
  for (list<int>::const_reverse_iterator p = b.rbegin();
       p != b.rend(); ++p) {
    if (p != b.rbegin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  system("pause");
  return 0;
}
