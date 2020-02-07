//
//  main.cpp
//  RatInMaze
//
//  Created by Portran Lu on 2020/2/7.
//  Copyright © 2020 Algo. All rights reserved.
//

#include <iostream>
#define N 4
using namespace std;
void RatInMaze();
int isSafe(int x,int y,int Maze[N][N],int Sol[N][N]);
int RatInMazeUtil(int x,int y,int moveX[], int moveY[],int Maze[N][N],int Sol[N][N]);
void printMap(int Sol[N][N]);
//
void printMap(int Sol[N][N]){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<Sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
int RatInMazeUtil(int x,int y,int moveX[], int moveY[],int Maze[N][N],int Sol[N][N]){
    int nextX=0,nextY=0;
    if(x==N-1 && y==N-1)
        return 1;
    for(int i=0;i<N;++i){
        nextX = x + moveX[i];
        nextY = y + moveY[i];
        if(isSafe(nextX,nextY,Maze,Sol) == 1){
            Sol[nextX][nextY] = 1;
            if(RatInMazeUtil(nextX,nextY,moveX,moveY,Maze,Sol)==1){
                return 1;
            }else{
                Sol[nextX][nextY] = 0;
            }
        }
    }
    return 0;
}
int isSafe(int x,int y,int Maze[N][N],int Sol[N][N]){
    return (x>=0 && y>=0 && x<N && y<N && Maze[x][y]==1 && Sol[x][y]!=1);
}
void RatInMaze(){
    int Maze[N][N]={{1, 0, 0, 0},
                    {1, 1, 0, 1},
                    {0, 1, 0, 0},
                    {1, 1, 1, 1}};
    int Sol[N][N]={-1};
    int moveX[N]={1,-1,0,0};
    int moveY[N]={0,0,-1,1};

    Sol[0][0] = 1;
    
    if(RatInMazeUtil(0,0,moveX,moveY,Maze,Sol)==0)
        cout<<"no ans";
    else
        printMap(Sol);
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    RatInMaze();
    std::cout << "Hello, World!\n";
    return 0;
}
