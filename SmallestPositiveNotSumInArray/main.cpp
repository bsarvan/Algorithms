//
//  main.cpp
//  SmallestPositiveNotSumInArray
//
//  Created by bsarvan on 25/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Given a sorted array, find the smallest positive integer that is not the sum of a subset of the array.
 
 For example, for the input [1, 2, 3, 10], you should return 7.
 
 Do this in O(N) time.
 
 */
#include <iostream>
#include <vector>
using namespace std;

int smallestSum(vector<int> A) {
    int n = A.size() - 1;
    int impossible_sum = 1;
    
    for (int i=0;i<=n;i++) {
        if (A[i] <= impossible_sum) {
            impossible_sum += A[i];
        } else {
            break;
        }
    }
    return (impossible_sum);
}

int main(int argc, const char * argv[]) {
//    vector<int> A = {1,2,3,10};
    vector<int> A = {1,1,3,5,8,21};
    
    cout<<"Smallest Sum  - ";
    cout<<smallestSum(A)<<endl;
    return 0;
}
