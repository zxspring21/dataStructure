#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <conio.h>
#include <windows.h>
#include <process.h>

using namespace std;

class Time {
public:
  Time() { _min = 0; _sec = 0; }
  int min() const { return _min; }
  int sec() const { return _sec; }
  
  Time operator++(int) {
    Time ret = *this;
    _sec++;
    if (_sec >= 60) {
      _sec -= 60;
      _min += 1;
      _min %= 60;
    }
    return ret;
  }
  
  Time &operator++() {
    _sec++;
    if (_sec >= 60) {
      _sec -= 60;
      _min += 1;
      _min %= 60;
    }
   return *this;
  }

  Time operator--(int) {
    Time ret = *this;
    _sec--;
    if (_sec < 0) {
      _sec += 60;
      _min -= 1;
      _min = (_min+60)%60;
    }
    return ret;
  }
  
  Time &operator--() {
    _sec--;
    if (_sec < 0) {
      _sec += 60;
      _min -= 1;
      _min = (_min+60)%60;
    }
    return *this;
  }

private:
  int _min;
  int _sec;
};

ostream &operator<<(ostream &s, const Time &t) {
  s << setw(2) << setfill('0') << t.min() << ":" << setw(2) << t.sec();
  return s;
}


int main() {
  Time data;
  
  cout << "\r" << data;
  char ch;
  while ( (ch = getch()) != 27) {
    if (ch == '+') {
      data++;
    } else if (ch == '-') {
      data--;
    }
    cout << "\r" << data;
  }
  return 0;
}
