//
//  main.cpp
//  N Queens
//
//  Created by Portran Lu on 2020/2/7.
//  Copyright © 2020 Algo. All rights reserved.
//

#include <iostream>
#define N 4
using namespace std;
int NQueens();
int NQueensUtil(int x,int y,int numberOfTimes,int Sol[][N]);
void printMap(int Sol[][N]);
int isSafe(int x,int y,int numberOfTimes,int Sol[][N]);
//
int isSafe(int x,int y,int numberOfTimes,int Sol[][N]){
    int moveX[]= {1,2,3,-1,-2,-3,
                    1,2,3,-1,-2,-3,
                    0,0,0,0,0,0,
                    1,2,3,-1,-2,-3,
    };
    int moveY[]= {1,2,3,-1,-2,-3,
                    0,0,0,0,0,0,
                    1,2,3,-1,-2,-3,
                    -1,-2,-3,1,2,3,
        
    };
    int numberOfMoveTimes = (int)sizeof(moveX)/sizeof(moveX[0]);
    int nextX, nextY =0;
    for(int i=0;i<numberOfMoveTimes;++i){
        nextX = x+ moveX[i];
        nextY = y+ moveY[i];
        //There're present queen which happen conflicts in the chess
        if(nextX>=0 && nextY>=0 && nextX<N && nextY<N && Sol[nextX][nextY]==1){
            return 0;
        }
    }
    return 1;
}

void printMap(int Sol[][N]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<Sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

int NQueensUtil(int x,int y,int numberOfTimes,int Sol[][N]){
    
    if(numberOfTimes==N) return 1;
    for(int i=x;i<N;++i){
        for(int j=0;j<N;++j){
            if(isSafe(i,j,numberOfTimes,Sol)==1){
                Sol[i][j]=1;
                if(NQueensUtil(i+1, y, numberOfTimes+1, Sol)==1){
                    return 1;
                }else{
                    Sol[i][j]= 0;
                }
            }
        }
    }
    return 0;
}

int NQueens(){
    int Sol[N][N]={0};
    if(NQueensUtil(0, 0, 0, Sol)==0){
        cout<<"No Ans";
    }else{
        printMap(Sol);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    NQueens();
    return 0;
}
