#include <iostream>
#include <cstdlib>
template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      
  ForwardListNode<ElemType> *link;   
};

// 新增迭代器類別
template<class ElemType>
class ForwardListIterator {
 public:
  ForwardListIterator(ForwardListNode<ElemType> *p) {
    p_ = p;
  }
  ForwardListIterator<ElemType> &operator++() {
    p_ = p_->link;
    return *this;
  }
  ForwardListIterator<ElemType> operator++(int) {
    ForwardListIterator<ElemType> ret = *this;
    p_ = p_->link;
    return *this;
  }
  bool operator!=(const ForwardListIterator<ElemType> &rhs) {
    return this->p_ != rhs.p_;
  }
  bool operator==(const ForwardListIterator<ElemType> &rhs) {
    return this->p_ == rhs.p_;
  }
  ElemType &operator*() {
    return p_->data;
  }
  ElemType *operator->() {
    return &p_->data;
  }
    
 private:
  ForwardListNode<ElemType> *p_;
};
 
template<class ElemType>
class ForwardList {
 public:
  typedef ForwardListNode<ElemType> Node;
  typedef ForwardListIterator<ElemType> Iterator;

  ForwardList() {
    size_ = 0; 
    head_ = 0;
  }
  explicit ForwardList(int n);
  ~ForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void PushFront(const ElemType &elem);
  void PopFront();
  void Insert(int pos, const ElemType &elem);
  void Erase(int pos);

  // 新增下列兩個函式:
  Iterator Begin() { return head_; }
  Iterator End()   { return NULL;  }
 
  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

 private:
  int size_;
  Node *head_;
};

template<class ElemType>
ForwardList<ElemType>::ForwardList(int n) {
  size_ = n;
  head_ = n == 0 ? 0 : new Node();
  Node *cur = head_;
  for (int i = 1; i < n; ++i) {
    cur->link = new Node();
    cur = cur->link;
  }
  cur->link = NULL;
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
void ForwardList<ElemType>::PushFront(const ElemType &elem) {
  Node *ins = new Node();
  ins->data = elem;
  ins->link = head_;
  size_++;
  head_ = ins;
} 

template<class ElemType>
void ForwardList<ElemType>::PopFront() {
  Node *del = head_;
  size_--;
  head_ = head_->link;
  delete del;
} 

template<class ElemType>
void ForwardList<ElemType>::Insert(int pos, const ElemType &elem) {
  ++size_;
  if (pos == 0) {
    Node *ins = new Node();
    ins->data = elem;
    ins->link = head_;
    head_ = ins;
  } else {
    Node *p = head_;
    for (int i = 0; i < pos - 1; ++i) { p = p->link; }  
    Node *ins = new Node(); 
    ins->data = elem;
    ins->link = p->link;
    p->link = ins;
  } 
}

template<class ElemType>
void ForwardList<ElemType>::Erase(int pos) {
  --size_;
  if (pos == 0) {
    Node *del = head_;
    head_ = head_->link;
    delete del;
  } else {
    Node *p = head_;
    for (int i = 0; i < pos - 1; ++i) { p = p->link; }
    Node *del = p->link;
    p->link = del->link; 
    delete del;
  }
} 

int main() {
  using std::cout;
  using std::endl;

  ForwardList<int> b(10);
  for (int i = 0; i < 10; ++i) {
    b[i] = i;
  }

  const ForwardListIterator<int> begin = b.Begin();
  const ForwardListIterator<int> end   = b.End(); 
  for (ForwardListIterator<int> p = begin; p != end; ++p) {
    cout << *p << endl;
  } 
  system("pause");
  return 0;
}
