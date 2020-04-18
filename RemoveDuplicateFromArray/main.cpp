//
//  main.cpp
//  RemoveDuplicateFromArray
//
//  Created by bsarvan on 15/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int start=1;
    for (int end=1;end<nums.size();end++) {
        if (nums[end] == nums[end-1]) continue;
        nums[start++]=nums[end];
    }
    
    return start;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to remove duplicates from sorted array"<<endl;
    //vector<int> nums = {1,1,2};
    vector<int> nums = {1,1,2,2,3,4,5,5};
    int len = removeDuplicates(nums);
    
    for(int i=0;i<len;i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
