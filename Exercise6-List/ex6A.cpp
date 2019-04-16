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
    head_ = NULL;
  }
  explicit ForwardList(int n);
  ~ForwardList();

  int Size() const;
  bool Empty() const;

 private:
  Node *head_;  // 指向第一個節點 
};

template<class ElemType>
ForwardList<ElemType>::ForwardList(int n) {
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
int ForwardList<ElemType>::Size() const {
   Node *cur = head_;
   static int i=0;
   while(cur!=NULL){
     i++;
     cur = cur->link;
   }
   return i;
}

template<class ElemType>
bool ForwardList<ElemType>::Empty() const {
  if(head_ == NULL)	return true;
  else			return false;
} 

int main() {
  using std::cout;
  using std::endl;
 
  ForwardList<int> a(5);
  cout << "a.Size(): " << a.Size() << endl;

  ForwardList<double> b;
  cout << "b.Size(): " << b.Size() << endl;

  ForwardList<double> c(10);
  cout << "c.Size(): " << c.Size() << endl;

  cout << "a.Empty(): " << a.Empty() << endl
       << "b.Empty(): " << b.Empty() << endl
       << "c.Empty(): " << c.Empty() << endl; 
  system("pause");
  return 0;
}
