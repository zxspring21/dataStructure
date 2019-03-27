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

  void Reserve(int n);
  int Capacity() const { return capacity_; }

  int &At(int i)      { return data_[i]; }
  int At(int i) const { return data_[i]; }

  int &operator[](int i)      { return At(i); }  
  int operator[](int i) const { return At(i); }  

  IntVector &operator=(const IntVector &rhs);

 private:
  int size_;
  int capacity_;
  int *data_;
};

IntVector::IntVector() {
  capacity_ = size_ = 0;
  data_ = NULL;
}

IntVector::IntVector(const IntVector& rhs) {
  capacity_ = size_ = rhs.Size();
  data_ = new int[capacity_];
  for (int i = 0; i < rhs.size_; ++i) data_[i] = rhs.data_[i];
} 

IntVector::IntVector(int n) {
  capacity_ = size_ = n;
  data_ = new int[capacity_];
}

IntVector &IntVector::operator=(const IntVector &rhs) {
  if (this != &rhs) {
    delete [] data_;
    capacity_ = size_ = rhs.Size();
    data_ = new int[capacity_]; 
    for (int i = 0; i < size_; ++i) data_[i] = rhs[i];
  }
  return *this;
} 

// 新增 Reverse 函式:  
void IntVector::Reserve(int n) {
  if (n > capacity_) {
    int *new_data = new int[n];
    for (int i = 0; i < size_; ++i) new_data[i] = data_[i];
    delete [] data_;
    data_ = new_data; 
    capacity_ = n;
  }
}

void IntVector::Resize(int n) {
  if (n <= capacity_) {
    size_ = n; 
  } else if (n > capacity_) {
    Reserve(n);
    size_ = n;
  }
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
    cout << "Size:     " << a.Size() << "\tCapacity: " << a.Capacity() << endl;
    a.Resize(i+1);
    a[a.Size()-1] = i;
  }
  cout << "a: " << a << endl;
  cout << endl;

  IntVector b;
  b.Reserve(5);
  for (int i = 0; i < 5; ++i) {
    cout << "Size:     " << b.Size() << "\tCapacity: " << b.Capacity() << endl;
    b.Resize(i+1);
    b[b.Size()-1] = i;
  }
  cout << "b: " << b << endl;
  cout << endl;

  system("pause");
  return 0; 
}
