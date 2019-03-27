#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <process.h>

using namespace std;

void call_from_thread(void *) {
  cout << "Hello world" << endl;
}

int main() {
  _beginthread(call_from_thread, 0, NULL);  
  system("pause");
  return 0;
}
