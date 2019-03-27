#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class IntHasher {
 public:
  IntHasher(int size) { size_ = size; }
  inline int operator()(int v) {
    return v % size_;
  }

 private:
  int size_;
};


class StringHasher {
 public:
  StringHasher(int size) { size_ = size; }
  inline int operator()(string v) {
    int k = 0;
    for (size_t i = 0; i < v.size(); ++i) {
      k += v[i];
    } 
    return k % size_;
  } 

 private:
  int size_;
};

template<class Type, class Hasher>
class Hash {
 public:
  Hash(int n = 10) : hf_(n) {
    data_.resize(n);
    for (int i = 0; i < n; ++i) {
      data_[i].first = false; 
    }
  }

  void Insert(const Type &v) {
    int i = hf_(v);
    while (data_[i].first == true && data_[i].second != v) {
      i = (i+1) % data_.size();
    }
    if (data_[i].first == false) { 
      data_[i] = make_pair(true, v);
    }
  }

  bool Search(const Type &v) {
    int i = hf_(v);
    while (data_[i].first == true && data_[i].second != v) {
      i = (i+1) % data_.size();
    }
    return (data_[i].first == true && data_[i].second == v);
  }
 
 private:
  vector<pair<bool, Type> > data_;
  Hasher hf_;
};

template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  vector<int> a;
  for (int i = 1; i <= 10; ++i) a.push_back(rand()%10);
  cout << "a: " << a << endl;

  Hash<int, IntHasher> b;
  for (size_t i = 0; i < a.size(); ++i) b.Insert(a[i]);

  for (int i = 0; i < 10; ++i) {
    if (b.Search(i)) {
      cout << "找到 " << i << endl; 
    } else {
      cout << "找不到 " << i << endl; 
    }
  }
  cout << endl;

  vector<string> c;
  c.push_back("Hello");
  c.push_back("This");
  c.push_back("is");
  c.push_back("a");
  c.push_back("book");
  cout << "c: " << c << endl;

  Hash<string, StringHasher> d;
  for (size_t i = 0; i < c.size(); ++i) {
    d.Insert(c[i]);
  } 

  vector<string> e;
  e.push_back("Hello");
  e.push_back("This");
  e.push_back("is");
  e.push_back("a");
  e.push_back("hook");

  for (size_t i = 0; i < e.size(); ++i) {
    if (d.Search(e[i])) {
      cout << "找到 " << e[i] << endl; 
    } else {
      cout << "找不到 " << e[i] << endl; 
    }
  }
  cout << endl;

  system("pause");
  return 0;
}
