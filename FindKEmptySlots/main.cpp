//
//  main.cpp
//  FindKEmptySlots
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 
 There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
 
 Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
 
 For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
 
 Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.
 
 If there isn't such day, output -1.
 
 Example -
 Input:
 flowers: [1,3,2]
 k: 1
 Output: 2
 Explanation: In the second day, the first and the third flower have become blooming.
 
 
 Input:
 flowers: [1,2,3]
 k: 1
 Output: -1
 
 
 
 */
int kEmptySlots(vector<int>& flowers, int k) {
    
    int res = INT_MAX;
    int *day = new int[flowers.size() + 1];
    
    memset(day,'\0',flowers.size());
    
    for (int i = 0; i < flowers.size(); i++) {
        // day[i] is the day when the flower at position i blooms
        // day[0] is useless here
        day[flowers[i]] = i+1;
    }
    cout<<"Postion / Days - ";
    for(int m=1;m<=flowers.size();m++){
        cout<<day[m]<<" ";
    }
    cout<<endl;
    
    // we now are supposed to find a subarray of day[left, right] where its length is k+2
    // and all i that left < i < right, we have day[i] > day[left] and day[i] > day[right]
    int left = 1, right = k + 2;
    for (int i = 2; right < flowers.size()+1; i++) {
        if (i == right) {
            cout<<"Here i = "<<i<<", Day[left] "<<day[left]<<", Day[right] "<<day[right]<<endl;
            // found a sub array
            res = min(res, max(day[left], day[right]));
            left = i;
            right = left + k + 1;
        } else if (day[i] < day[left] || day[i] < day[right]) {
            cout<<"For i = "<<i<<"Day[left] "<<day[left]<<", Day[right] "<<day[right]<<endl;
            left = i;
            right = left + k + 1;
        }
    }
    
    return (res == INT_MAX)?-1:res;
}

int main(int argc, const char * argv[]) {
    
    vector<int> flowers = {1,3,2,5,7,6};
    
    cout<<"Flowers Positions - ";
    for(auto c:flowers) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    int day = kEmptySlots(flowers, 1);
    cout<<"Day - "<<day<<endl;
    
    return 0;
}
