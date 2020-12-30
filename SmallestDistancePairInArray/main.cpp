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

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums.back() - nums[0];
    // left --> The minimum distance
    // right --> The maximum distance
    // mid --> The mid of distance
    while (left < right) {
        int mid = left + (right - left) / 2, cnt = 0, start = 0;
        // Find the number of pairs in vector, with distance greater than mid
        for (int i = 0; i < n; ++i) {
            cout<<"i - "<<i<<", mid - "<<mid<<", Pairs - "<<nums[i]<<", "<<nums[start]<<endl;
            while (start < n && nums[i] - nums[start] > mid) {
                cout<<"Pairs - "<<nums[i]<<", "<<nums[start]<<endl;
                ++start;
            }
            cnt += i - start;
            cout<<"Count here is "<<cnt<<endl<<endl ;
        }
        cout<<"Number of Pairs - "<<cnt<<", greater than mid - "<<mid<<endl;
        if (cnt < k) {
            cout<<"Going Right"<<endl;
            left = mid + 1;
        }
        else {
            cout<<"Going Left"<<endl;
            right = mid;
        }
    }
    return right;
}

int main(int argc, const char * argv[]) {
    cout<<"Find the smallest distance pair"<<endl;
    
    //vector<int> A = {1,2,3,4};
     vector<int> A = {1,2,4,10,15,19};
    //vector<int> A = {1,2,3,4,5,6,7,8};
    
    int result = smallestDistancePair(A, 1);
    cout<<"Result - "<<result<<endl<<endl;
    return 0;
}
