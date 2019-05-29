#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>
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
  // 新增複製建構式 
  ForwardList(const ForwardList &x);
  ~ForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void PushFront(const ElemType &elem);
  void PopFront();
  // 新增清除函式: 
  void Clear();
  // 新增交換函式:
  void Swap(ForwardList<ElemType> &x); 

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }
  // 新增賦值運算子多載 
  ForwardList &operator=(const ForwardList &rhs);
 
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
ForwardList<ElemType>::ForwardList(const ForwardList<ElemType> &x) {
  size_ = x.size_;
  if (x.size_ > 0) {
    head_ = new Node();
    head_->data = x.head_->data;
    Node *to   = head_;
    Node *from = x.head_; 
    while (from->link != NULL) { 
      to->link = new Node();
      to->link->data = from->link->data;
      to = to->link;
      from = from->link;
    }
    to->link = NULL;
  } else {
    head_ = NULL;
  }
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
  head_ = ins;
  size_++;
} 

template<class ElemType>
void ForwardList<ElemType>::PopFront() {
  Node *del = head_;
  head_ = head_->link;
  delete del;
  size_--;
} 

template<class ElemType>
void ForwardList<ElemType>::Clear() {
  Node *cur = head_;
  while(cur != NULL){
     Node *del = cur;
     cur = cur->link;
     delete del;
     size_--;
  }
}

template<class ElemType>
void ForwardList<ElemType>::Swap(ForwardList<ElemType> &x) {
    
    
    /*
    Node *from = x.head_;
    Node *to = head_;
    ElemType tmp;
     */
    //allocate another memory
    
    
    //directly change content
    /*
    if(x.size_ < size_){
        while(from->link){
            tmp = from->data;
            from->data = to->data;
            to->data = tmp;
            from = from->link;
            to = to->link;
        }
        
        while(to->link){
            Node *del = to;
            Node *newNode = new Node();
            newNode->data = to->data;
            from->data =
            
        }
     
    }else{
        while(to->link){
            tmp = from->data;
            to->data = from->data;
            from->data = tmp;
            from = from->link;
            to = to->link;
        }
        while(from->link){
            Node *newNode = new Node();
            newNode->data = from->link->data;
            newNode->link = NULL;
            to->link = newNode;
            from = from->link;
            to = to->link;
        }
    }
    */
}

template<class ElemType>
ForwardList<ElemType> &ForwardList<ElemType>::operator=(
    const ForwardList<ElemType> &rhs) {
  // Copy-and-Swap idiom
  ForwardList<ElemType> tmp(rhs); // 呼叫複製建構式
  Swap(tmp);                      // 呼叫交換函式 
  return *this;                   // 此時會呼叫 tmp 的解構式 
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
  for (int i = 0; i < 5; ++i) { a[i] = i; }
  ForwardList<int> b = a;
  cout << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i < 3; ++i) { b.PushFront(i+5); }
  cout << "a: " << a << endl
       << "b: " << b << endl;
       //<< a.Size()<<endl
       //<< b.Size()<<endl;
  b.Swap(a);
  cout << "b.Swap(a);" << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  b.Clear();
  cout << "b.Clear();" << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i <3; ++i) { b.PushFront(i+8); }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  b = a;
  cout << "b = a; " << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i < b.Size(); ++i) { b[i] = i+10; }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  ForwardList<int> c;
  ForwardList<int> d(c);
  cout << "c: " << c << endl
       << "d: " << d << endl; 
  system("pause");
  return 0;
}
