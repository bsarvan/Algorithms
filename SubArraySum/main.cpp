//
//  main.cpp
//  SubArraySum
//
//  Created by Bharat Sarvan on 18/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

  

 Example 1:

 Input: nums = [1,1,1], k = 2
 Output: 2
 Example 2:

 Input: nums = [1,2,3], k = 3
 Output: 2
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
//        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int idx = i;
            while(sum <= k) {
                sum += nums[idx++];
                if (sum == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    int subarraySum_v2(vector<int> & nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        
        mp.emplace(0,0);
        //Build the map of cummulative sums
        for (const int &v : nums) {
            sum += v;
            
            int req = sum - k;
            if (req == 0) {
                count++;
            }
            count += mp.count(req) ? mp[req] : 0;
            mp[sum]++;
        }
        
        return count;
    }
    
    
    int subarraySum_v3(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            int cum_sum = 0;
            int count = 0;
            
            //Build the map of cummulative sums
            for (const int &v : nums) {
                cum_sum += v;
                
                if (cum_sum == k) {
                    count++;
                }
                
                if (mp.find(cum_sum - k) != mp.end()) {
                    count += mp[cum_sum - k];
                }
                mp[cum_sum]++;
            }
            
            return count;
        }
};




int main(int argc, const char * argv[]) {
    cout<<"Algorithm to compute the total number of maximum continous subarray with sum equal to K"<<endl;
    vector<int> input = {1,2,3};
    int K = 3;
    Solution sol;
    
    int result = sol.subarraySum(input, K);
    int result2 = sol.subarraySum_v2(input, K);
    cout<<result<<endl;
    
    cout<<result2<<endl;
    return 0;
}
