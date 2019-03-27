#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <process.h>

using namespace std;

void call_from_thread(void *data) {
  int count = 1;
  while (true) {
    cout << "Hi, I'm thread #" << *(int *)data << " (" << count << ")" << endl;
    Sleep(1000);
    count++;
  }
}

int main() {
  int data[3] = {0, 1, 2};

  for (int i = 0; i < 3; ++i) {
    _beginthread(call_from_thread, 0, &data[i]);
    // Can we use _beginthread(call_from_thread, 0, &i) ?
  }  
  system("pause");
  return 0;
}
