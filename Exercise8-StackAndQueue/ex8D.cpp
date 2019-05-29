#include <iostream>
#include <vector>
#include <cstdlib>

template<class ElemType>
class Queue {
 public:
  ElemType Front() const {
    // TODO
      return data_.front();
  }
  void Push(const ElemType &elem) {
    // TODO
      data_.push_back(elem);
  }
  void Pop() {
    // TODO
      //data_.pop_front();
      data_.erase(data_.begin());
  }
  bool Empty() const {
    return data_.empty();
  }
 private:
  std::vector<ElemType> data_;
};


int main() {
  using std::cout;
  using std::endl;

  Queue<int> q;
  for (int i = 1; i <= 5; ++i) {
    q.Push(i);
  }
  cout << "q.Front(): " << q.Front() << endl;

  cout << "q: ";
  while (!q.Empty()) {
    cout << q.Front();
    q.Pop();
    cout << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}
