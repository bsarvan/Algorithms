//
//  main.cpp
//  SmallestDistancePairInArray
//
//  Created by bsarvan on 02/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.
 
 Input:
 nums = [1,3,1]
 k = 1
 Output: 0
 Explanation:
 Here are all the pairs:
 (1,3) -> 2
 (1,1) -> 0
 (3,1) -> 2
 Then the 1st smallest distance pair is (1,1), and its distance is 0.
 */

#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of less than distance d
int FindPairs(vector<int> nums, int d) {
    int count = 0, j = 0;
    
    for (int i = 0; i < nums.size();i++) {
        while(j < i and nums[i] - nums[j] > d) j++;
        count += i - j;
    }
    return count;
}


int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums[0];
    // left --> The minimum distance
    // right --> The maximum distance
    // mid --> The mid of distance
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        int count = FindPairs(nums, mid);
        cout<<"# pairs less than "<<mid<<" are "<<count<<endl;
        
        if (count < k) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

/*
 Complexity Analysis

 Time Complexity: O(N \log{W} + N \log{N})O(NlogW+NlogN), where NN is the length of nums, and WW is equal to nums[nums.length - 1] - nums[0]. The \log WlogW factor comes from our binary search, and we do O(N)O(N) work inside our call to possible (or to calculate count in Java). The final O(N\log N)O(NlogN) factor comes from sorting.

 Space Complexity: O(1)O(1). No additional space is used except for integer variables.
 */


class Solution {
public:
    int smallestDistancePairV2(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi) left++;
                count += right - left;
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};

int main(int argc, const char * argv[]) {
    cout<<"Find the smallest distance pair"<<endl;
    
    //vector<int> A = {1,2,3,4};
     vector<int> A = {1,2,4,10,15,19};
    //vector<int> A = {1,2,3,4,5,6,7,8};
    
    int result = smallestDistancePair(A, 4);
    cout<<"Result - "<<result<<endl<<endl;
    
    
    Solution sol;
    int res = sol.smallestDistancePairV2(A, 4);
    cout<<"Res = "<<res<<endl;
    
    return 0;
}
