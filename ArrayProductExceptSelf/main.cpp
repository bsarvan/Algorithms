//
//  main.cpp
//  ArrayProductExceptSelf
//
//  Created by bsarvan on 28/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Example:

 Input:  [1,2,3,4]
 Output: [24,12,8,6]
 Note: Please solve it without division and in O(n).

 Follow up:
 Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 
 
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    void printVector(vector<int> V) {
        for(auto v:V) {
            cout<<v<<" ";
        }
        
        cout<<endl;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int> result;
        
        if (nums.empty()) {
            return {};
        }
        
        int prod = 1;
        for (int i=0;i<nums.size();i++) {
            prod *= nums[i];
            left.emplace_back(prod);
        }
        
        printVector(left);
        
        prod = 1;
        for (int i=nums.size()-1;i>=0;i--) {
            prod *=nums[i];
            right.insert(right.begin(),prod);
        }
        
        printVector(right);
        
        for (int i=0;i<nums.size();i++) {
            if (i == 0) {
                result.emplace_back(right[i+1]);
            } else if (i == nums.size() - 1) {
                result.emplace_back(left[i-1]);
            } else {
                cout<<left[i-1]<<" "<<right[i+1]<<endl;
                result.emplace_back(left[i-1]*right[i+1]);
            }
        }
        return result;
    }
};



int main(int argc, const char * argv[]) {
    
    vector<int> A = {1,2,3,4};
    
    Solution obj;
    
    vector<int> res = obj.productExceptSelf(A);
    
    obj.printVector(res);
    
    return 0;
}
