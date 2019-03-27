#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  vector<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%20);
  cout << "a: ";
  for (vector<int>::iterator p = a.begin(); 
       p != a.end(); ++p) {
    if (p != a.begin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  list<int> b;
  for (int i = 1; i <= 10; ++i) b.push_back(rand()%20);
  cout << "b: ";
  for (list<int>::iterator p = b.begin();
       p != b.end(); ++p) {
    if (p != b.begin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  cout << "a~: ";
  for (vector<int>::reverse_iterator p = a.rbegin();
       p != a.rend(); ++p) {
    if (p != a.rbegin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  cout << "b~: ";
  for (list<int>::reverse_iterator p = b.rbegin();
       p != b.rend(); ++p) {
    if (p != b.rbegin()) cout << " ";
    cout << *p;
  }
  cout << endl;

  system("pause");
  return 0;
}
