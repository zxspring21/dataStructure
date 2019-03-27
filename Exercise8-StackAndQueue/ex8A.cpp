#include <iostream>
#include <vector>
#include <cstdlib>

template<class ElemType>
class Stack {
 public:
  ElemType Top() const {
    // TODO
  }
  void Push(const ElemType &elem) {
    // TODO
  }
  void Pop() {
    // TODO
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

  Stack<int> s;
  for (int i = 1; i <= 5; ++i) {
    s.Push(i);
  }
  cout << "s.Top(): " << s.Top() << endl;

  cout << "s: ";
  while (!s.Empty()) {
    cout << s.Top();
    s.Pop();
    cout << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}
