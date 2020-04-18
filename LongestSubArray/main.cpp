//
//  main.cpp
//  LongestSubArray
//
//  Created by bsarvan on 23/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*

 Longest Subarray having sum of elements atmost ‘k’
 Given an array of integers, our goal is to find the length of largest subarray having sum of its elements atmost ‘k’ where k>0.
 
 Examples:
 
 Input : arr[] = {1, 2, 1, 0, 1, 1, 0},
 k = 4
 Output : 5
 Explanation:
 {1, 2, 1} => sum = 4, length = 3
 {1, 2, 1, 0}, {2, 1, 0, 1} => sum = 4, length = 4
 {1, 0, 1, 1, 0} =>5 sum = 3, length = 5
 
 */


#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> A = {1,2,1,0,1,1,0};
    int k = 4;
    int maxLen = 0;

    
    for (int i = 0; i < A.size(); i++) {
        int sum = 0;
        int len = 0;
        
        int iter_index = i;
        while(sum <= k && iter_index<A.size()) {
            sum += A[iter_index++];
            len++;
        }
        cout<<"Length - "<<len<<", Sum - "<<sum<<endl;
        
        if (len > maxLen) {
            maxLen = len;
        }
    }
    
    cout<<"MaxLength - "<<maxLen<<endl;
    
    return 0;
}
