//
//  main.cpp
//  MaximumMinimumArray
//
//  Created by Bharat Sarvan on 02/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//


/*
 
 Problem: Given a sorted array, rearrange it in maximum-minimum form. Input: [1, 2, 3, 4, 5, 6, 7] Output: [7, 1, 6, 2, 5, 3, 4]
 
 */
#include <iostream>
#include <vector>
using namespace std;


vector<int> MaxMinArray(vector<int> A) {
    vector<int> result(A.size());
    
    int start = 0;
    int stop = A.size() - 1;
    
    for ( int i = 0; i < A.size(); i++) {
        if ( i % 2 == 0) {
            result[i] = A[stop--];
        } else {
            result[i] = A[start++];
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {

    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    vector<int> result = MaxMinArray(input);
    
    cout<<"The MinMax Array is - ";
    for(auto &r :  result) {
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
