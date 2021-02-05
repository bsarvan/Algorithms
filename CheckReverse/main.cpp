//
//  main.cpp
//  CheckReverse
//
//  Created by Bharat Sarvan on 24/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 
 Problem: Given an array of integers, find if reversing a sub-array makes the array sorted.
 
 Solution: In this algorithm start and stop are the boundary of reversed sub-array whose reversal makes the whole array sorted.
 
 */

#include <iostream>
#include <vector>
using namespace std;


bool CheckReverse(vector<int> arr) {
    int start = -1;
    int end = -1;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        if ( arr[i] > arr[i + 1]) {
            start = i;
            break;
        }
    }
    
    for (int i = start; i < arr.size() - 1; i++) {
        if ( arr[i] < arr[i + 1]) {
            end = i;
            break;
        }
    }
    
    if ((arr[start] > arr[end + 1]) or (arr[end] < arr[start - 1])) {
        return false;
    }
    
    for (int i = end; i < arr.size() - 1; i++) {
        if ( arr[i] > arr[i + 1]) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> input = {1,2,3,6,5,4,7,9,8};
    bool result = CheckReverse(input);
    
    cout<<result<<endl;
    return 0;
}
