//
//  main.cpp
//  FindMissingRanges
//
//  Created by bsarvan on 14/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 
 
 Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

 Example:

 Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 Output: ["2", "4->49", "51->74", "76->99"]
 
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int start;
        int end;
        
        if (nums.empty()) {
            if (lower == upper) {
               result.emplace_back(to_string(lower));
            } else {
               result.emplace_back(to_string(lower) + "->" + to_string(upper));
            }
            return result;
            
        }
        
        for (int i = 1; i < nums.size(); i++) {
           if (nums[i] - nums[i-1] > 1) {
               int start = nums[i-1] + 1;
               int end = nums[i] - 1;
               
               if (start == end) {
                   result.emplace_back(to_string(start));
               } else {
                   result.emplace_back(to_string(start) + "->" + to_string(end));
               }
           }
        }
        
        if (nums[nums.size() - 1] < upper) {
            start = nums[nums.size() - 1] + 1;
            result.emplace_back(to_string(start) + "->" + to_string(upper));
        }
        
        return result;
    }
};



vector<string> findMissingRangesV2(vector<int> A, int start, int end) {
    vector<string> result;
    int prev = start - 1;
    
    for (int i=0;i<A.size();i++) {
        int curr = A[i];
        if (curr - prev >= 2) {
            if (prev + 1 == curr - 1) {
                result.emplace_back(to_string(prev + 1));
            } else {
                result.emplace_back(to_string(prev+1) + "->" + to_string(curr - 1));
            }
        }
        prev = curr;
    }
    
    if (A[A.size() - 1] < end) {
        result.emplace_back(to_string(A[A.size() - 1] + 1) + "->" + to_string(end));
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
//    vector<int> R = {0,1, 3, 50, 75};
    vector<int> R = {10, 15, 50, 75, 80};
    cout<<"Program to find the missing ranges in stream of numbers"<<endl;
    
    
    Solution sol;
    
//    vector<string> result = sol.findMissingRanges(R, 0, 99);
    vector<string> result = findMissingRangesV2(R, 0, 99);
    
    for(auto s:result) {
        cout<<s<<endl;
    }
    return 0;
}
