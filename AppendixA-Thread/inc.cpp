#include <iostream>
#include <cstdlib>
#include <vector>

#include <windows.h>
#include <process.h>
#include <conio.h>

using namespace std;
struct Data {
  int id;
  int len;
  int *array;
  HANDLE event;
};

void call_from_thread(void *arg) {
  Data *data = static_cast<Data *>(arg);
  for (int i = 0; i <= data->len; ++i) {
    data->array[i] += 10;
  }
  SetEvent(data->event);
}

int main() {
  
  Data data[3];
  HANDLE hEvents[3];

  int N = 100;
  vector<int> v(N);

  cout << "[Before] ";
  for (int i = 0; i < N; ++i) {
    v[i] = i;
    cout << v[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < 3; ++i) {
    data[i].id = i;
    int idx = N / 3 * data[i].id;
    if (idx + N / 3 < N) {
      data[i].len = N / 3;
    } else {
      data[i].len = N - idx;
    } 
    data[i].array = &v[idx];
    data[i].event = hEvents[i] = CreateEvent(NULL, false, false, NULL);
  }

  for (int i = 0; i < 3; ++i) {
    _beginthread(call_from_thread, 0, &data[i]);
  } 
  WaitForMultipleObjects(3, hEvents, true, INFINITE);

  cout << endl << "[After] ";
  for (int i = 0; i < N; ++i) {
    cout << v[i] << " ";
  }
  cout << endl;

  system("pause");
  return 0;
}
