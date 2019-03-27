#include <iostream>
#include <cstdlib>
#include <vector>

#include <windows.h>
#include <process.h>
#include <conio.h>

using namespace std;

int count = 0;

struct Data {
  int id;
  HANDLE event;
};

void call_from_thread(void *arg) {
  Data *data = static_cast<Data *>(arg);
  /* 以下這段不能修改: */ 
  int old_count = count;
  Sleep(1); // 故意讓他等一下 
  count = old_count+1;
  SetEvent(data->event);
  /* 到此不能修改 */ 
}

int main() {
  Data data[50];
  HANDLE hEvents[50];


  for (int i = 0; i < 50; ++i) {
    data[i].id = i;
    data[i].event = hEvents[i] = CreateEvent(NULL, false, false, NULL);
  }

  for (int i = 0; i < 50; ++i) {
    _beginthread(call_from_thread, 0, &data[i]);
  } 
  WaitForMultipleObjects(50, hEvents, true, INFINITE);

  cout << "Count: " << count << endl;

  system("pause");
  return 0;
}
