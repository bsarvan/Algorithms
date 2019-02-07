//
//  main.cpp
//  MaxConsecutiveOnes_II
//
//  Created by bsarvan on 15/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/*
 Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
 
 Input: [1,0,1,1,0]
 Output: 4
 Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
 After flipping, the maximum number of consecutive 1s is 4.
 
 */

#include <iostream>
#include <vector>
using namespace std;


int findMaxConsecutiveOnes(vector<int> nums) {
    int prevCount = -1, currCount = 0, ans = 0;
    for (auto num : nums){
        if (num == 0){
            ans = max(ans, prevCount + currCount + 1);
            prevCount = currCount;
            currCount = 0;
        }else{
            currCount ++;
        }
    }
    ans = max(ans, prevCount + currCount + 1);
    return ans;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to find max consecutive ones"<<endl;
    vector<int> V = {1,1,0,1,1,0,0,1,0};
    
    int res = findMaxConsecutiveOnes(V);
    cout<<"Max Consecutive ones after flipping one 0 is "<<res<<endl;
    cout<<endl;
    return 0;
}
