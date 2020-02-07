//
//  main.cpp
//  Knight's Tour
//
//  Created by Portran Lu on 2020/2/6.
//  Copyright © 2020 Algo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define N 8
using namespace std;
int KT();
int KTUtil(int x,int y,int moveTime,int sol[N][N],int moveX[N],int moveY[N]);
void printMap(int sol[N][N]);
int isSafe(int x,int y,int sol[N][N]);

void printMap(int sol[N][N]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<setw(2)<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
int KTUtil(int x,int y,int moveTime,int sol[N][N],int moveX[N],int moveY[N]){
    //start from (0,0)
    int nextX=0,nextY=0;
    if(moveTime==N*N)
        return 1;
    for(int i=0;i<N;++i){
            nextX = x + moveX[i];
            nextY = y + moveY[i];
            if(isSafe(nextX,nextY,sol)==1){
                sol[nextX][nextY] = moveTime;
                if(KTUtil(nextX,nextY,moveTime+1,sol,moveX,moveY)==1){
                    return 1;
                }else{
                    sol[nextX][nextY] = -1;
                }
            }
    }
    return 0;
}
int KT(){
    int sol[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            sol[i][j]=-1;
        }
    }
    int moveX[N]={2,1,-1,-2,-2,-1,1,2};
    int moveY[N]={1,2,2,1,-1,-2,-2,-1};
    sol[0][0] = 0;
    if(KTUtil(0,0,1,sol,moveX,moveY)==0){
        cout<<"no answer"<<endl;
        return 0;
    }else{
        printMap(sol);
    }
    return 1;
}
int isSafe(int x,int y,int sol[N][N]){
    return (x>=0 && y>=0 && x<N && y< N && sol[x][y]==-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    KT();
    
    return 0;
}
