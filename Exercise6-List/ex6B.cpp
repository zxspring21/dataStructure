#include <iostream>
#include <cstdlib>
template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // 元素 
  ForwardListNode<ElemType> *link;      // 下一個節點的指標 
};

template<class ElemType>
class ForwardList {
  typedef ForwardListNode<ElemType> Node;

 public:
  ForwardList() {
    size_ = 0; 
    head_ = NULL;
  }
  explicit ForwardList(int n);
  ~ForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  // 實作下列操作:
  ElemType &Front()             { return head_->data; }
  const ElemType &Front() const { return head_->data; } 
  ElemType &Back()              { 
     printf("ha\n");
     //return (ElemType&)((const ForwardList*)this) -> Back();
     return const_cast<ElemType&> (const_cast<const ForwardList*>(this)-> Back());
  }
  const ElemType &Back() const  {
     Node *cur = head_;
     while(cur->link !=NULL) cur =cur->link;
       return cur->data;
  }

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

 private:
  int size_;
  Node *head_;  // 指向第一個節點 
};

template<class ElemType>
ForwardList<ElemType>::ForwardList(int n) {
  size_ = n;
  head_ = n == 0 ? NULL : new Node();
  Node *cur = head_;
  for (int i = 1; i < n; ++i) {
    cur->link = new Node();
    cur = cur->link;
  }
  cur->link = 0;
}

template<class ElemType>
ForwardList<ElemType>::~ForwardList() {
  Node *cur = head_;
  while (cur != NULL) {
    Node *del = cur;
    cur = cur->link;
    delete del;
  }
}

template<class ElemType>
ElemType &ForwardList<ElemType>::At(int i) { 
  return (ElemType&)((const ForwardList *)this)->At(i);
}

template<class ElemType>
const ElemType &ForwardList<ElemType>::At(int i) const {
  Node *cur = head_;
  for (int k = 0; k < i; ++k) {
    cur = cur->link;
  }
  return cur->data;
}
 
template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const ForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;
 
  ForwardList<int> a(5);
  for (int i = 0; i < 5; ++i) {
    a[i] = i + 3;
  }
  cout << "a: " << a << endl;
  cout << "a.Front(): " << a.Front() << endl;
  cout << "a.Back():  " << a.Back() << endl;

  const ForwardList<int> &b = a;
  cout << "b: " << b << endl;
  cout << "b.Front(): " << b.Front() << endl;
  cout << "b.Back():  " << b.Back() << endl;

  system("pause");
  return 0;
}
