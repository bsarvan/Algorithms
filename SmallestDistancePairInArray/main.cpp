//
//  main.cpp
//  SmallestDistancePairInArray
//
//  Created by bsarvan on 02/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums.back() - nums[0];
    while (left < right) {
        int mid = left + (right - left) / 2, cnt = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            cout<<"i - "<<i<<", mid - "<<mid<<endl;
            while (start < n && nums[i] - nums[start] > mid) {
                cout<<"Pairs - "<<nums[start]<<", "<<nums[i]<<endl;
                ++start;
            }
            cnt += i - start;
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
    
    int result = smallestDistancePair(A, 2);
    cout<<"Result - "<<result<<endl<<endl;
    return 0;
}
