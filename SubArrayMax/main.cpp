//
//  main.cpp
//  SubArrayMax
//
//  Created by bsarvan on 30/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
 
 For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:
 
 10 = max(10, 5, 2)
 7 = max(5, 2, 7)
 8 = max(2, 7, 8)
 8 = max(7, 8, 7)
 Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout<<"Program to find sub-array max"<<endl;
    vector<int> V = {10, 5, 2, 7, 8, 7};
    priority_queue<int, vector<int>> pq;
    vector<int> max_list;
    
    int k = 3;
    int sub_len = 0;
    for(int i=0;i <= V.size() - 1;i++){
        cout<<"Pushing on PQ - "<<V[i]<<endl;
        pq.push(V[i]);
        
        cout<<"Queue Size - "<<pq.size()<<endl;
        sub_len++;
        if (sub_len == k) {
            cout<<"Top of PQ is - "<<pq.top()<<endl;
            max_list.emplace_back(pq.top());
            int start_val = V[i-(k-1)];
            if (start_val == pq.top())
                pq.pop();
            sub_len--;
        }
        
        cout<<"Size of the Queue - "<<pq.size()<<endl;
    }
    
    for(auto c:max_list) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    return 0;
}
