#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

int main() {
  using namespace std;

  stack<int> s;
  cout << "請輸入你的後序運算式 (例如: 5 6 * 3 + =) :" << endl; 
  while (true) {
    string input;
    cin >> input;
    if (input == "=") {
      cout << "計算結果為 " << s.top() << endl; 
      break;
    }else if (input == "+") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a+b);
    } else if (input == "-") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a-b);
    } else if (input == "*") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a*b);
    } else if (input == "/") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a/b);
    } else /* 以上皆非時我們假設為數字 */ {
      int v;
      std::stringstream(input) >> v;
      s.push(v);
    }
  }
  std::system("pause");
  return 0;
} 
