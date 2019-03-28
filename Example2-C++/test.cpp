#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


float Echo(float v){
   return 2*v;
}
/*
float Echo(double v){
   return 3*v;
}
*/


int main() {
  printf("%f\n",Echo(3));
  return 0;
} 
