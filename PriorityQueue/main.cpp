//
//  main.cpp
//  PriorityQueue
//
//  Created by bsarvan on 14/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void showpq(priority_queue<int,vector<int>,greater<>> s)
{
    cout<<"Contents of Priority Queue are - ";
    priority_queue<int,vector<int>,greater<>> qq = s;
    while(!qq.empty())
    {
        cout<<qq.top()<<" ";
        qq.pop();
    }
    cout<<endl;
    return;
}

void pushpq(priority_queue<int,vector<int>,greater<>> &s,int score)
{
    s.push(score);
    if(s.size() > 3) {
        s.pop();
    }
    return;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test Priority Queue"<<endl;
    priority_queue<int,vector<int>,greater<>> q;          //Min Heap
    
    pushpq(q, 91);
    pushpq(q, 90);
    pushpq(q, 95);
    vector<int> vec = {1,2,3,4};
    
    
    showpq(q);
    q.pop();
        
    showpq(q);
    pushpq(q, 89);
    pushpq(q, 99);
    showpq(q);
    
    
    
    /*
    pushpq(q, 89);
    showpq(q);
    pushpq(q, 97);
    showpq(q);
     */
    return 0;
}



