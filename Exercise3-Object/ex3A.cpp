#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
   int num1=0,num2=0, result=0;
   cout<<"Input the first num1 = ";
   cin>>num1;   
   cout<<"Input the second num2 = ";
   cin>>num2;
   result = num1 * num2; \\ if the result too big, then it will overflow to the negative number
   cout<< "The num1 * num2 = "<< result<<endl;


   return 0;
}
