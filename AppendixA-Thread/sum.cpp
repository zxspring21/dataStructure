#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <process.h>
#include <conio.h>

using namespace std;
struct Data {
  int id;
  HANDLE event;
  CRITICAL_SECTION *cs;
};

void call_from_thread(void *arg) {
  Data *data = static_cast<Data *>(arg);
  for (int i = 1; i <= 5; ++i) {
    EnterCriticalSection(data->cs);
    cout << "Hi, I'm thread #" << data->id << " (" << i << ")" << endl;
    LeaveCriticalSection(data->cs);
    Sleep(1000);
  }
  SetEvent(data->event);
}

int main() {
  
  Data data[3];
  HANDLE hEvents[3];

  CRITICAL_SECTION cs;
  InitializeCriticalSection(&cs);

  for (int i = 0; i < 3; ++i) {
    data[i].id = i;
    data[i].event = hEvents[i] = CreateEvent(NULL, false, false, NULL);
    data[i].cs = &cs;
  }

  for (int i = 0; i < 3; ++i) {
    _beginthread(call_from_thread, 0, &data[i]);
  } 
  WaitForMultipleObjects(3, hEvents, true, INFINITE);
  system("pause");
  return 0;
}
