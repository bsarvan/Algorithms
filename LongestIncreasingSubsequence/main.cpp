//
//  main.cpp
//  LongestIncreasingSubsequence
//
//  Created by bsarvan on 30/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequenceDP(vector<int> A) {
    // Vector L to hold the length of longest increasing subsequence until ith position
    // Worst case the maximum length of longest subsequence can be 1
    vector<int> L(A.size(),1);
    
    // Compute the length of the longest subsequence until each index i.
    for (int i = 1; i<A.size(); i++) {
        
        // Compute the number of digits less than the digit at index i
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
        cout<<"Max Subsequence Len at "<<i<<" - "<<L[i]<<endl;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    
    vector<int> V = {7,3,8,4,2,6};
    
//    int LIS = INT_MIN;
//    for (int i = 0; i < V.size(); i++) {
//        int T = V[i];
//        int count = 0;
//        for (int j = i + 1 ; j < V.size(); j++) {
//            if (T < V[j]) {
//                T = V[j];
//                count++;
//                LIS = max(LIS, count);
//            } else {
//                continue;
//            }
//        }
//    }
//
//    cout<<"LIS - "<<LIS<<endl;
    
    
    longestIncreasingSubsequenceDP(V);
    return 0;
}
