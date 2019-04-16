#include <ctime>
#include <cstdio>
#include <iostream>
using namespace std;


int main(){
   int a;
   cin>>a;
   time_t t= time(NULL);
   cout<<"Start to calcuate.."<<endl;
   cin>>a;
   cout<<"Termination..\n Cost Time: ";
   t= time(NULL) - t;
   if(t > 60)
      cout<< t/60<<" m, "<< t%60<<" s"<<endl;
   else
      cout<< t<<" s"<<endl;
   return 0;



}
