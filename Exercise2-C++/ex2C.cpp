#include <stdio.h>
#include <stdlib.h>

/* TODO: 請定義兩個 Scan 函式 */
void Scan(int &tmp){
   scanf("%d",&tmp);
}
void Scan(float &tmp){
   scanf("%f",&tmp);
}

int main() {
  int a;
  float b;
  printf("請輸入整數: "); 
  Scan(a);
  printf("請輸入浮點數: "); 
  Scan(b);

  printf("a: %d\n", a);
  printf("b: %f\n", b);
  system("pause");
  return 0;
} 
