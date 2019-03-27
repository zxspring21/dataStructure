#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <process.h>
#include <conio.h>

using namespace std;
struct Data {
  int id;
  HANDLE event;
};

void call_from_thread(void *data) {
  for (int i = 1; i <= 5; ++i) {
    cout << "Hi, I'm thread #" << ((Data *)data)->id << " (" << i << ")" << endl;
    Sleep(1000);
  }
  SetEvent(((Data *)data)->event);
}

int main() {
  
  Data data[3];
  HANDLE hEvents[3];
  for (int i = 0; i < 3; ++i) {
    data[i].id = i;
    data[i].event = hEvents[i] = CreateEvent(NULL, false, false, NULL);
  }
  for (int i = 0; i < 3; ++i) {
    _beginthread(call_from_thread, 0, &data[i]);
  } 
  WaitForMultipleObjects(3, hEvents, true, INFINITE);
  system("pause");
  return 0;
}
