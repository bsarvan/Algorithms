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
    vector<int> L(A.size(),1);
    
    for (int i = 1; i<A.size(); i++) {
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
