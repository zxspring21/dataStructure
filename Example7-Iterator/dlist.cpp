#include <iostream>
#include <cstdlib>
template<class ElemType>
struct ListNode {
  ElemType           data;      
  ListNode<ElemType> *prev;
  ListNode<ElemType> *next;   
};

// 新增迭代器類別
template<class ElemType>
class ListIterator {
 public:
 public: 
  ListIterator(ListNode<ElemType> *p) {
    p_ = p;
  }
  ListIterator<ElemType> &operator++() {
    p_ = p_->next;
    return *this;
  }
  const ListIterator<ElemType> operator++(int) {
    ListIterator<ElemType> ret = *this;
    p_ = p_->next;
    return ret;
  }
  bool operator!=(const ListIterator<ElemType> &rhs) {
    return p_ != rhs.p_;
  }
  bool operator==(const ListIterator<ElemType> &rhs) {
    return p_ == rhs.p_;
  }
  ElemType &operator*() {
    return p_->data;
  }
  ElemType *operator->() {
    return &p_->data;
  }

 private: 
  ListNode<ElemType> *p_;
};

// 新增反向迭代器 
template<class ElemType>
class ListReverseIterator {
 public:
  ListReverseIterator(ListNode<ElemType> *p) {
    p_ = p; 
  }
  ListReverseIterator<ElemType> &operator++() {
    p_ = p_->prev;
    return *this;
  }
  const ListReverseIterator<ElemType> operator++(int) {
    ListReverseIterator<ElemType> ret = *this;
    p_ = p_->prev;
    return ret;
  }
  bool operator!=(const ListReverseIterator<ElemType> &rhs) {
    return p_ != rhs.p_;
  }
  bool operator==(const ListReverseIterator<ElemType> &rhs) {
    return p_ == rhs.p_;
  }
  ElemType &operator*() {
    return p_->data;
  }
  ElemType *operator->() {
    return &p_->data;
  }

 private: 
  ListNode<ElemType> *p_;
};
 
template<class ElemType>
class List {
 public:
  typedef ListNode<ElemType> Node;
  typedef ListIterator<ElemType> Iterator;
  typedef ListIterator<const ElemType> ConstIterator;
  typedef ListReverseIterator<ElemType> ReverseIterator;
  typedef ListReverseIterator<const ElemType> ConstReverseIterator;
 
  List() {
    size_ = 0; 
    head_ = tail_ = NULL;
  }
  explicit List(int n);
  ~List();

  int Size() const { return size_; }

  Iterator Begin() { return head_; }
  Iterator End()   { return NULL;  }
  ReverseIterator Rbegin() { return tail_; }
  ReverseIterator Rend()   { return NULL;  }
 
 private:
  int size_;
  Node *head_;
  Node *tail_;
};

template<class ElemType>
List<ElemType>::List(int n) {
  size_ = n;
  if (n == 0) {
    head_ = NULL;
  } else {
    head_ = new Node();
    head_->prev = NULL;
  }
  Node *cur = head_;
  for (int i = 1; i < n; ++i) {
    cur->next = new Node();
    cur->next->prev = cur;
    cur = cur->next;
  }
  cur->next = NULL;
  tail_ = cur;
}
  
template<class ElemType>
List<ElemType>::~List() {
  Node *cur = head_;
  while (cur != NULL) {
    Node *del = cur;
    cur = cur->next;
    delete del;
  }
}


int main() {
  using std::cout;
  using std::endl;

  List<int> b(10);
  {
    int i = 0;
    for (ListIterator<int> p = b.Begin(); p != b.End(); ++p) {
      *p = i;
      ++i;
    }
  }
  cout << "b: ";
  for (ListIterator<int> p = b.Begin(); p != b.End(); ++p) {
    if (p != b.End()) { cout << " "; } 
    cout << *p;
  } 
  cout << endl;

  cout << "b: ";
  for (ListReverseIterator<int> p = b.Rbegin(); p != b.Rend(); ++p) {
    if (p != b.Rend()) { cout << " "; } 
    cout << *p;
  } 
  cout << endl;

  system("pause");
  return 0;
}
