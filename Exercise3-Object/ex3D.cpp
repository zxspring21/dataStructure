#include <iostream>
#include <cstdlib>

class BigInt {
 public:
  BigInt() {}
  BigInt(unsigned int v) {
    for (int i = 0; i < 20; i++) {
      data_[i] = v % 10;
      v /= 10;
    }
  } 
  void Print() const {
    int is_zero = 1;
    for (int i = 20-1; i >= 0; --i) {
      if (data_[i] != 0) is_zero = 0;
      if (!is_zero)
        std::cout << data_[i];
    }
  }

  const BigInt operator*(const BigInt &rhs) const {
    return Multiply(rhs);
  }

  const BigInt operator+(const BigInt &rhs) const {
    return Add(rhs);
  }

 private:
  const BigInt Multiply(const BigInt &rhs) const {
    BigInt r;
    for (int i = 0; i < 20; ++i) {
      r.data_[i] = 0;
    }
    for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
        int k = i + j;
        if (k < 20) {
          r.data_[k] += data_[i] * rhs.data_[j];
        }
      }
    }
    int carry = 0;
    for (int i = 0; i < 20; ++i) {
      int next_carry = (r.data_[i]+carry)/10;
      r.data_[i] = (r.data_[i]+carry)%10;
      carry = next_carry;
    }
    return r;
  }

  const BigInt Add(const BigInt &rhs) const {
    BigInt r;
    for (int i = 0; i < 20; ++i) {
      r.data_[i] = 0;
    }
    for (int i = 0; i < 20; ++i) {
      r.data_[i] = data_[i] + rhs.data_[i];
    }
    int carry = 0;
    for (int i = 0; i < 20; ++i) {
      int next_carry = (r.data_[i]+carry)/10;
      r.data_[i] = (r.data_[i]+carry)%10;
      carry = next_carry;
    }
    return r;
  }

  int data_[20];
};

std::ostream& operator<<(std::ostream &lhs, const BigInt &rhs) {
  rhs.Print();  // 為了簡化所以這麼寫, 實際上是不好的, 因為 lhs 不一定是 cout 
  return lhs;
}

int main() {

  /* TODO */
  BigInt num1 = 1234567;
  BigInt num2 = 9999999;
  BigInt num3 = 7654321;
  std::cout << "result = ";
  std::cout << ( num1 + num2 * num3 )*num1 <<std::endl;
  system("pause");
  return 0;
}


