#include <iostream>
#include <cstdlib>

struct BigInt {
  int data[20];
};

BigInt Create(unsigned int v);
BigInt Multiply(const BigInt &a, const BigInt &b);
BigInt Add(const BigInt &a, const BigInt &b);
void Print(const BigInt &r);

int main() {
  BigInt a = Create(999999999);
  BigInt b = Create(123456789);
  BigInt r = Multiply(a, b);

  std::cout << "999999999 * 123456789 == ";
  Print(r);
  std::cout << std::endl;

  system("pause");
  return 0;
}

BigInt Create(unsigned int v) {
  BigInt r;
  for (int i = 0; i < 20; i++) {
    r.data[i] = v % 10;
    v /= 10;
  }
  return r;
}

BigInt Add(const BigInt &a, const BigInt &b) {
  BigInt r;
  for (int i = 0; i < 20; ++i) {
    r.data[i] = 0;
  }
  for (int i = 0; i < 20; ++i) {
    r.data[i] = a.data[i] + b.data[i];
  }
  int carry = 0;
  for (int i = 0; i < 20; ++i) {
    int next_carry = (r.data[i]+carry)/10;
    r.data[i] = (r.data[i]+carry)%10;
    carry = next_carry;
  }
  return r;
}

BigInt Multiply(const BigInt &a, const BigInt &b) {
  BigInt r;
  for (int i = 0; i < 20; ++i) {
    r.data[i] = 0;
  }
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j) {
      int k = i + j;
      if (k < 20) {
        r.data[k] += a.data[i] * b.data[j];
      }
    }
  }
  int carry = 0;
  for (int i = 0; i < 20; ++i) {
    int next_carry = (r.data[i]+carry)/10;
    r.data[i] = (r.data[i]+carry)%10;
    carry = next_carry;
  }
  return r;
}

void Print(const BigInt &r) {
  int is_zero = 1;
  for (int i = 20-1; i >= 0; --i) {
    if (r.data[i] != 0) is_zero = 0;
    if (!is_zero)
      std::cout << r.data[i];
  }
}


