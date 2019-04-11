#include <iostream>
#include <cstdlib>

class IntVector {
 public:
  IntVector();
  IntVector(const IntVector &rhs);
  explicit IntVector(int n);
  ~IntVector() { delete [] data_; } 

  int Size() const { return size_; } 
  void Resize(int n); 
  int &At(int i)      { return data_[i]; }
  int At(int i) const { return data_[i]; }

  // 實作下列功能:
  void PushFront(int elem) {
    int *newData = new int[size_+1];
    for(int i=0; i< size_; i++){
       newData[i+1] = data_[i];
    }
    newData[0] = elem;
    delete[] data_;
    data_ = newData; 
    size_ = size_ + 1;
  }
  void PopFront() {
    int *newData = new int[size_-1];
    for(int i=0; i< size_; i++){
       newData[i] = data_[i+1];
    }
    delete[] data_;
    data_ = newData;
    size_ = size_ - 1;
  }

  int &operator[](int i)      { return At(i); }  
  int operator[](int i) const { return At(i); }  

  IntVector &operator=(const IntVector &rhs);

 private:
  int size_;
  int *data_;
};

IntVector::IntVector() {
  size_ = 0;
  data_ = NULL;
}

IntVector::IntVector(const IntVector& rhs) {
  size_ = rhs.Size();
  data_ = new int[rhs.size_];
  for (int i = 0; i < rhs.size_; ++i) data_[i] = rhs.data_[i];
} 

IntVector::IntVector(int n) {
  size_ = n;
  data_ = new int[n];
}

IntVector &IntVector::operator=(const IntVector &rhs) {
  if (this != &rhs) {
    delete [] data_;
    size_ = rhs.Size();
    data_ = new int[rhs.size_]; 
    for (int i = 0; i < rhs.size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
} 

void IntVector::Resize(int n) {
  int *new_data = new int[n];
  for (int i = 0; i < size_ && i < n; ++i) {
    new_data[i] = data_[i];
  }
  delete [] data_;
  data_ = new_data;
  size_ = n;
}

std::ostream &operator<<(std::ostream &lhs, const IntVector &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}


int main() {
  using namespace std;
  IntVector a;
  for (int i = 0; i < 5; ++i) {
    a.PushFront(i);
  }

  cout << "a: " << a << endl;

  for (int i = 0; i < 3; ++i) {
    a.PopFront();
  }
  cout << "a: " << a << endl;

  system("pause");
  return 0; 
}

