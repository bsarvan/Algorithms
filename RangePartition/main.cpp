//
//  main.cpp
//  RangePartition
//
//  Created by Bharat Sarvan on 24/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 Problem: Given an array of integer and a range. Write an algorithms to partition array so that values smaller than range come to left, then values under the range followed with values greater than the range.
 
 First solution: The basic approach is to use three index. First left, second right and third to traverse the array.  Index left starts form 0, Index right starts from N-1. We traverse the array whenever we find a value lower than range we swap it with the value at start and increment start. And whenever we finds a value greater than range we swaps this value with right and decrement right. When traversal is complete we have the array partitioned about range.
 
 */
#include <iostream>
#include <vector>
using namespace std;

void RangePartition(vector<int> &arr, int low, int high) {
    int start = 0;
    int end = (int)arr.size() - 1;
    int i = 0;
    
    while(i <= end) {
        if (arr[i] < low) {
            swap(arr[start++], arr[i++]);
        } else if (arr[i] > high) {
            swap(arr[end--], arr[i]);
        } else {
            i++;
        }
    }
    
    return;
}


int main(int argc, const char * argv[]) {
//    vector<int> input = {1, 21, 2, 20, 3, 19, 4, 18, 5, 17, 6, 16, 7, 15, 8, 14, 9, 13, 10, 12, 11};
    vector<int> input = {1,5,6,10,7,8,9,2,4,3};
    
    RangePartition(input, 4, 6);
    
    cout<<"Range Partitioned Array - ";
    for( auto a : input) {
        cout<<a<<" ";
    }
    
    cout<<endl<<endl;
    
    return 0;
}
