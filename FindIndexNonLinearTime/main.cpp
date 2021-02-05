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
    
    while(1) {
        int m = (l + r)/2;
        if (A[m] == target) {
            return m;
        } else if (A[m] > target) {
            r = m;
        } else {
            l = (m + 1) % A.size();
        }
    }
    
    return 0;
}


int search(vector<int> A, int low, int high, int target) {
    int mid = low + (high - low)/2;
    if (A[mid] == target) {
        return mid;
    }
    
    if (low > high) {
        return -1;
    }
    
    if (A[mid] > A[low]) {
        if (target >= A[low] and target < A[mid]) {
            return search(A, low, mid - 1, target);
        } else {
            return search(A, mid + 1, high, target);
        }
    } else if (A[mid] < A[high]) {
        if (target > A[mid] and target <= A[high]) {
            return search(A, mid + 1, high, target);
        } else {
            return search(A, low, mid - 1, target);
        }
    } else if (A[low] == A[mid]) {
        if (A[mid] != A[high]) {
            return search(A, mid + 1, high, target);
        } else {
            int result = search(A, low, mid - 1, target);
            if (result == -1) {
                return search(A, mid + 1, high, target);
            } else {
                return result;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> V = {13, 18, 25, 2, 8, 10};
    
    cout<<"Algorithm to find the index of a number in less than linear time"<<endl;
    int result = FindIndexOfNumber(V, 8);
//    int result = search(V, 0, V.size() - 1, 8);
    
    
    cout<<"Index of target is "<<result<<endl;
    return 0;
}
