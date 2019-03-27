#include <stdio.h>
#include <stdlib.h>

void Swap(int a, int b) {
  int t = a;
  a = b;
  b = t;
}

int main() {
  int a, b;
  printf("a: "); 
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
 
  Swap(a, b);

  printf("[Swap 之後]\n" 
         "a: %d\n"
         "b: %d\n", a, b); 

  system("pause");
  return 0;
}
