//
//  main.cpp
//  RainWaterTrapping
//
//  Created by bsarvan on 26/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int trap2(const vector<int> &height) {
    // initialize output
    int result = 0;
    
    // maximum element on left and right
    int left_max = 0, right_max = 0;
    
    // indices to traverse the array
    int lo = 0, hi = height.size()-1;
    
    while(lo <= hi)
    {
        if(height[lo] < height[hi])
        {
            if(height[lo] > left_max)
                // update max in left
                left_max = height[lo];
            else
                // water on curr element = max - curr
                result += left_max - height[lo];
            lo++;
        }
        else
        {
            if(height[hi] > right_max)
                // update right maximum
                right_max = height[hi];
            else
                result += right_max - height[hi];
            hi--;
        }
    }
    return result;
}

int trap(vector<int>& height) {
    auto l = height.begin(), r = height.end() - 1;
    int level = 0, water = 0;
    while (l != r + 1) {
        int lower = *l < *r ? *l++ : *r--;
        cout<<"Lowest level till this index : "<<lower<<endl;
        level = max(level, lower);
        cout<<"Before - level:"<<level<<",water:"<<water<<endl;
        water += level - lower;
        cout<<"After -  level:"<<level<<",water:"<<water<<endl;
        cout<<"=============================="<<endl;
    }
    return water;
}


int main(int argc, const char * argv[]) {
    cout<<"Find maximum water trapped"<<endl;
    vector<int> A = {1,0,2,0,3,0,1};
    int res = trap(A);
    cout<<"Maximum Water Trapped - "<<res<<endl;
    return 0;
}
