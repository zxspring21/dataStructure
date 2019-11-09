//
//  main.cpp
//  onlineJudge
//
//  Created by Portran Lu on 2019/11/8.
//  Copyright © 2019 Devops. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;
int solution[5];    // 用來存放一組可能的情形
bool used[5];
 
void print_solution()   // 印出一組可能的情形
{
    for (int i=0; i<5; i++)
        cout << i << ' ';
    cout << endl;
}
void backtrack(int n)   // n 為現在正在枚舉的維度
{
    // it's a solution
    if (n == 5)
    {
        print_solution();
        return;
    }
 
    // 逐步枚舉數字1到10，並且遞迴下去，繼續枚舉之後的維度。
    for (int i=1; i<=10; ++i)
    {
        solution[n] = i;
        backtrack(n+1);
    }
}
int main(){
    //ASCII
    backtrack(0);
    return 0;
}
