//  If you meet compiling error, following the next line direction and entering it in the command line
//  g++ -std=c++11 -o Greedy_meetingSchedule Greedy_meetingSchedule.cpp
//  main.cpp
//  greedyAlgo
//
//  Created by Portran Lu on 2019/7/1.
//  Copyright © 2019 Devops. All rights reserved.
//

#include <iostream> //cout
#include <vector> //vector
#include <queue> //priority_queue
//#include <utility> //pair, make_pair
//#include <functional> //greater
using namespace std;
//greedy algorithm
//how to use STL to solve the complicated problems
void GreedyAlgo(const vector<int> start, const vector<int> finish){
    /*
     1. Build the math model
     2. Divide and Conquer
     3. Get the local optimal solution
     *///based on iterative instead of dynamic programming which includes regress progress to divide and conquer
    
    //Problem: Meeting room which should be solved with arranging the scheduled system to maximize the utilization of meeting room
    //input: Start, end time
    //output: Following activities are selected 0 1 3 4 by start time
    
    //Solution:
    /*
     1. To store finish/start time into Prioirty Queue(PQ) and sort it by greater case
     2. Utilizing vector containter to store the start/finish from PQ
     3. Based on the current start time which larger than past end time to find the appropriate case
     */
    vector<int> answer;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    //Input the data
    for(int i= 0 ; i<start.size(); ++i){
        pq.push(make_pair(finish[i], start[i]) );
    }
    //input the first element regardless of conditions
    answer.push_back(pq.top().second);
    auto prev_finish = pq.top().first;
    pq.pop();
    //Utilize the algo core to find the answer
    while(!pq.empty()){
        auto cur = pq.top();
        auto cur_start = cur.second;
        if(cur_start > prev_finish ){
            answer.push_back(cur_start);
            prev_finish = cur.first;
        }
        pq.pop();
    }
    //print the answer
    for(vector<int>::iterator it=answer.begin(); it!=answer.end(); ++it){
        cout<< (*it)<<" ,"<< endl;
    }
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    
    GreedyAlgo(start, finish);
    
    return 0;
}

