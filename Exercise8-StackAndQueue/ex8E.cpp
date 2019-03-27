#include <iostream>
#include <stack>
#include <queue> 
#include <cstdlib>
#include <sstream>

using namespace std;

/* TODO */

int Evaluate(queue<string> q) {
  stack<int> s;
  while (!q.empty()) {
    string input = q.front();
    q.pop();
    if (input == "=") {
      return s.top();
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
    } else {
      int v;
      std::stringstream(input) >> v;
      s.push(v);
    }
  }
  return 0;
}

int main() {
  stack<string> s;
  queue<string> q;
  cout << "請輸入你的運算式 (例如: 3 + 5 * ( 6 + 5 ) =):" << endl; 
  while (true) {
    string input;
    cin >> input;
    if (input == "=") {
      while (!s.empty()) {
        q.push(s.top());
        s.pop();
      }
      q.push(input);  
      break;
    }
    /* TODO */
  }

  cout << "轉為後序表示法為: "; 
  {
    queue<string> o = q;
    while (!o.empty()) {
      cout << o.front() << " ";
      o.pop();
    }
  }
  cout << endl;
  cout << "計算結果為: " << Evaluate(q) << endl;
  std::system("pause");
  return 0;
} 
