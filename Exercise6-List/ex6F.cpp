#include <iostream>
#include <cstdlib>

template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // 元素 
  ForwardListNode<ElemType> *link;      // 下一個節點的指標 
};

template<class ElemType>
class OrderedForwardList {
  typedef ForwardListNode<ElemType> Node;

 public:
  OrderedForwardList() {
    size_ = 0; 
    head_ = NULL;
  }
  ~OrderedForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void Insert(const ElemType &elem);

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }
 
 private:
  int size_;
  Node *head_; 
};

template<class ElemType>
OrderedForwardList<ElemType>::~OrderedForwardList() {
  Node *cur = head_;
  while (cur != NULL) {
    Node *del = cur;
    cur = cur->link;
    delete del;
  }
}

template<class ElemType>
ElemType &OrderedForwardList<ElemType>::At(int i) { 
  return (ElemType&)((const OrderedForwardList *)this)->At(i);
}

template<class ElemType>
const ElemType &OrderedForwardList<ElemType>::At(int i) const {
  Node *cur = head_;
  for (int k = 0; k < i; ++k) {
    cur = cur->link;
  }
  return cur->data;
}

template<class ElemType>
void OrderedForwardList<ElemType>::Insert(const ElemType &elem) {
  /* TODO */
} 

template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const OrderedForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;
  OrderedForwardList<int> a;

  for (int i = 0; i < 3; ++i) { a.Insert(i+2); }
  cout << "a: " << a << endl;

  for (int i = 0; i < 3; ++i) { a.Insert(i); }
  cout << "a: " << a << endl;;

  for (int i = 0; i < 2; ++i) { a.Insert(4+i); }
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
