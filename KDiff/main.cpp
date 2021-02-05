//
//  main.cpp
//  KDiff
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 
 Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

  Example: Input :
     A : [1 3 5]
     k : 4
  Output : YES as 5 - 1 = 4
 Return 0 / 1 ( 0 for false, 1 for true ) for this problem

 Try doing this in less than linear space complexity.
 
 */
#include <iostream>
#include <vector>
using namespace std;


int diffPossible(vector<int> &A, int B) {
    int i = 0;
    int j = i + 1;
    
    while(i < A.size() and j < A.size()) {
        int diff = A[j] - A[i];
        if (diff == B and i != j) {
            return 1;
        } else if (diff < B) {
            j++;
        } else {
            i++;
        }
    }

    return 0;
}



int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find if the elements exists with diff equal to K"<<endl;
    vector<int> A = {1,3,5,6};
    
    int result = diffPossible_v2(A, 4);
    
    string res = result == 1? "YES":"NO";
    cout<<res<<endl;
    
    return 0;
}
