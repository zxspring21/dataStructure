#ifndef H_FLIST_
#define H_FLIST_


template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // 元素 
  ForwardListNode<ElemType> *link;      // 下一個節點的指標 
};

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
  typedef ForwardListIterator<const ElemType> ConstIterator;
  typedef ElemType ValueType;

  ForwardList() {
    size_ = 0; 
    head_ = 0;
  }
  explicit ForwardList(int n) {
    size_ = n;
    head_ = n == 0 ? 0 : new Node();
    Node *cur = head_;
    for (int i = 1; i < n; ++i) {
      cur->link = new Node();
      cur = cur->link;
    }
    cur->link = 0;
  }
  ~ForwardList() {
    Node *cur = head_;
    while (cur != 0) {
      Node *del = cur;
      cur = cur->link;
      delete del;
    }
  } 

  int Size() const { return size_; }
  ElemType &At(int i) {  return (ElemType&)((const ForwardList *)this)->At(i); } 
  const ElemType &At(int i) const {
    Node *cur = head_;
    for (int k = 0; k < i; ++k) {
      cur = cur->link;
    }
    return cur->data;
  } 
  void PushFront(const ElemType &elem) {
    Node *ins = new Node();
    ins->data = elem;
    ins->link = head_;
    head_ = ins;
    size_++;
  } 
  void PopFront() {
    Node *del = head_;
    head_ = head_->link;
    delete del;
    size_--;
  }
  void Insert(int pos, const ElemType &elem) {
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
    ++size_;
  }
  void Erase(int pos) {
    if (pos == 0) {
      Node *del = head_;
      head_ = head_->link;
      delete del;
    } else {
      // Step 1]
      Node *p = head_;
      for (int i = 0; i < pos - 1; ++i) { p = p->link; }
      Node *del = p->link;
      // Step 2]
      p->link = del->link; 
      // Step 3]
      delete del;
    }
    --size_;
  }  
  Iterator Begin()            { return head_; }
  ConstIterator Begin() const { return (typename ForwardList<const ElemType>::Node *)head_; }
  Iterator End()              { return 0;  }
  ConstIterator End()   const { return 0;  } 
  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

 private:
  
  int size_;
  Node *head_;  // 指向第一個節點 
};

#endif // H_FLIST_
