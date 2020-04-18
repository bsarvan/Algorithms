//
//  main.cpp
//  HouseRobDP
//
//  Created by bsarvan on 08/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int Rob(int n, vector<int> &nums) {
    vector<int> R(n);
    
    R[0] = nums[0];
    R[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        R[i] = max(R[i-1], nums[i] + R[i-2]);
    }
    return R[n-1];
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to indentify the maximum amount that can be stolen from houses"<<endl;
    vector<int> num = {1,2,3,4,5};
    
    int maxAmount = Rob(5, num);
    
    cout<<"Max Amount that can be stolen  - "<<maxAmount<<endl;
    return 0;
    
}
