//
//  main.cpp
//  FindIndexNonLinearTime
//
//  Created by Bharat Sarvan on 21/07/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 An sorted array of integers was rotated an unknown number of times.

 Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

 For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

 You can assume all the integers in the array are unique.
 
 */
#include <iostream>
#include <vector>
using namespace std;


int FindIndexOfNumber(vector<int> A, int target) {
    int l = 0;
    int r = A.size() - 1;
    
    while(l<r) {
        int m = l + (r-l)/2;
        if (A[m] > A[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    r = (A.size()- 1 + l) % A.size();
    cout<<"Lower Index = "<<l<<", Upper Index = "<<r<<endl;
    
    if (A[r] < target) {
        cout<<"Search Right"<<endl;
    } else {
        cout<<"Search Left"<<endl;
    }
    
//    while(1) {
//        int m = (l + r)/2;
//        if (A[m] == target) {
//            return m;
//        } else if (A[m] > target) {
//            r = m;
//        } else {
//            l = (m + 1) % A.size();
//        }
//    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    vector<int> V = {13, 18, 25, 2, 8, 10};
    
    cout<<"Algorithm to find the index of a number in less than linear time"<<endl;
    int result = FindIndexOfNumber(V, 8);
    
    cout<<"Index of target is "<<result<<endl;
    return 0;
}
