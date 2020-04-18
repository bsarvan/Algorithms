//
//  main.cpp
//  StackUsingHeap
//
//  Created by bsarvan on 16/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Sample program to test priority_queue on customer data types"<<endl;
    priority_queue<int> pq;
    
    pq.push(90);
    pq.push(80);
    pq.push(100);
    
    cout<<"Contents of PQ - ";
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
