#include <iostream>
#include <cstdlib>


template<typename ElemType>
struct ForwardListNode{
   ElemType		 	data; 
   ForwardListNode<ElemType>	*link;
};

template<typename ElemType>
class Forward_List{
   typedef ForwardListNode<ElemType> Node;
   
   public:
      Forward_List(){
	size_ = 0;
        head_ = NULL;
      }      

      explicit Forward_List(int n);
      ~Forward_List();

      int Size() const{ return size_;}
   private:
      Node *head_;
      int size_;
};

template<typename ElemType>
Forward_List<ElemType>::Forward_List(int n){
   size_ = n;
   head_ = n == 0? NULL: new Node();
   Node *cur = head_;
   for(int i=1; i<n; i++){
      cur->link = new Node();
      cur = cur->link;
   }
   cur->link = NULL;
}

template<typename ElemType>
Forward_List<ElemType>::~Forward_List(){
   Node *cur = head_;
   for(int i=0; i<size_; i++){
      Node *del = cur;
      cur = cur->link;
      delete del;
   }
}

int main(){
   using std::cout;
   using std::endl;
   Forward_List<int> list(5);
   cout << "List Size = " << list.Size() <<endl;
   system("pause"); 
   return 0;
}
