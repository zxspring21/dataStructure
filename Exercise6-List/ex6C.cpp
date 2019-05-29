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
  void PushFront(const ElemType &elem);
  void PopFront();
  // 新增下列函式: 
  void PushBack(const ElemType &elem);
  void PopBack();

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
  size_--;
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

// 下面是這兩個函式的實作: 
template<class ElemType>
void ForwardList<ElemType>::PushBack(const ElemType &elem) {
  Node *cur = head_;
  int numbers= Size();
  if(numbers ==0 ){
     head_ = new Node();
     head_->data = elem;
     head_->link = NULL;
  }else{
     for(int i=1; i<= numbers; i++){
        if(i == numbers)
           cur->link = new Node();
        cur = cur->link;
     }
     cur->data = elem;
     cur->link = NULL;
  }
  size_++;  
} 

template<class ElemType>
void ForwardList<ElemType>::PopBack() {
    Node *cur = head_;
    int numbers = Size();
    if(numbers==1){
        Node *del = cur->link;
        cur->link = NULL;
        delete del;
        size_--;
    }
        
    for(int i=1; i<=numbers-1; ++i){
        //std::cout<<i<<std::endl;
        if(i == (numbers-1) ){
            Node *del = cur->link;
            cur->link = NULL;
            delete del;
            size_--;
            break;
        }
        cur = cur->link;
    }
    
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

  ForwardList<int> a;
  for (int i = 0; i < 5; ++i) {  a.PushBack(i);  }
  cout << "a: " << a << endl;
  
  for (int i = 0; i < 3; ++i) {  a.PopBack();  }
  cout << "a: " << a << endl;

  for (int i = 0; i < 2; ++i) {  a.PopBack();  }
  cout << "a: " << a << endl;

  for (int i = 0; i < 5; ++i) {  a.PushBack(i);  }
  cout << "a: " << a << endl;
  
  system("pause");
  return 0;
}
