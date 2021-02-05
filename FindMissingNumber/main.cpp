//
//  main.cpp
//  FindMissingNumber
//
//  Created by Bharat Sarvan on 08/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void FindMissingNumber(vector<int> nums) {
    
    for (int i = 1; i <= nums.size(); i++) {
        bool found = false;
        for (int j  = 0; j < nums.size(); j++) {
            if (nums[j] == i) {
                found = true;
            }
        }
        
        if (found == false) {
            cout<<"Missing numnber is "<<i<<endl;
        }
    }
    return;
}

void FindMissingNumber_v2(vector<int> nums) {
    int xorSum = 0;
    
    // Find XOR of all numbers in the range
    for (int i = 1; i <= nums.size() + 1; i++) {
        xorSum ^= i;
    }
    
    // Find XOR of all the numbers in the vector nums
    for (int i = 0; i < nums.size(); i++) {
        xorSum ^= nums[i];
    }
    
    cout<<"Missing number is "<<xorSum<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,4,5,6};
    
    FindMissingNumber(nums);
    FindMissingNumber_v2(nums);
    
    return 0;
}
