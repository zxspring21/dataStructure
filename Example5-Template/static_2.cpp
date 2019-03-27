#include <iostream>
#include <cstdlib>
using namespace std;

class Grade {
 public:
  static const int kMaxGrade = 100;
  static const int kMinGrade = 0;

  Grade()         { data_ = 0; }
  Grade(int v)    { data_ = v; }
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }

 private:
  int data_;
};

int main() {
  cout << "Max grade: " << Grade::kMaxGrade << endl
       << "Min grade: " << Grade::kMinGrade << endl;

  Grade a;
  cout << "Max grade: " << a.kMaxGrade << endl
       << "Min grade: " << a.kMinGrade << endl;
 
  system("pause");
  return 0;
}
