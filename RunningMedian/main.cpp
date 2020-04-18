//
//  main.cpp
//  RunningMedian
//
//  Created by bsarvan on 15/02/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printRunningMedian(vector<int> V) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;
    
    cout<<"Input Stream - ";
    for (auto v:V)
        cout<<v<<" ";
    cout<<endl;
    
    for(auto v:V) {
        if (min_heap.empty()) {
            min_heap.emplace(v);
        } else {
            cout<<"v - "<<v<<", min_heap - "<<min_heap.top()<<endl;
            if (v >= min_heap.top()) {
                cout<<"Emplacing to min_heap";
                min_heap.emplace(v);
                cout<<", Min-Heap - "<<min_heap.top()<<endl;
            } else {
                cout<<"Emplacing to max_heap"<<endl;
                max_heap.emplace(v);
            }
        }
        
        if (min_heap.size() > max_heap.size() + 1) {
            // Case 1 - Min Heap size is greater than Max Heap plus one
            // 1 2 3 | 4 5 6 7 8  - Move the median line towards right
            
            max_heap.emplace(min_heap.top());
            min_heap.pop();
            

        } else if (max_heap.size() > min_heap.size()) {
            // Case 2 - Max Heap size is greater than Min Heap
            // 1 2 3 4 5 | 6 7 8  - Move the median line towards left

            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }
        
        
        cout<<"Median - "<<(min_heap.size() == max_heap.size() ?
               0.5*(min_heap.top() + max_heap.top()) : min_heap.top())<<endl;
    }
    cout<<endl<<endl;
}

int main(int argc, const char * argv[]) {
    
    std::cout << "Computing running median of stream of numbers"<<endl;
    vector<int> vec = {1,0,3,5,2,0,1};
    printRunningMedian(vec);
    return 0;
}




