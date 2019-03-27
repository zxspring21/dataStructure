#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class ElemType>
void Heapify(vector<ElemType> &x, int low, int high) {
  int large_index = 2 * low + 1;
  ElemType temp = x[low];
  while (large_index <= high) {
    if (large_index < high && x[large_index] < x[large_index+1]) {
      large_index = large_index + 1;
    }
    if (temp > x[large_index]) {
      break;
    } else {
      x[low] = x[large_index];
      low = large_index;
      large_index = 2 * low + 1;
    }
  }
  x[low] = temp;
}


template <class ElemType>
void MakeHeap(vector<ElemType> &x) {
  for (int i = static_cast<signed>(x.size())/2-1; i >= 0; --i) {
    Heapify(x, i, x.size()-1);
  }
}

template <class ElemType>
void SortHeap(vector<ElemType> &x) {
  MakeHeap(x);
  for (int i = static_cast<signed>(x.size())-1; i > 0; --i) {
    swap(x[0], x[i]);
    Heapify(x, 0, i-1);       
  }
}

template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType>& rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  vector<int> heap;
  for (int i = 1; i <= 10; ++i) heap.push_back(rand()%20);
  cout << "heap: " << heap << endl;
  MakeHeap(heap);
  cout << "heap: " << heap << endl;
  
  SortHeap(heap);
  cout << "heap: " << heap << endl;

  system("pause");
  return 0;
}
