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

int trap(vector<int>& height) {
    auto l = height.begin(), r = height.end() - 1;
    int level = 0, water = 0;
    while (l != r + 1) {
        int lower = *l < *r ? *l++ : *r--;
        cout<<"Lowest level till this index - "<<lower<<endl;
        level = max(level, lower);
        cout<<"Max Level here  - "<<level<<endl;
        water += level - lower;
    }
    return water;
}


int main(int argc, const char * argv[]) {
    cout<<"Find maximum water trapped"<<endl;
    vector<int> A = {1,0,2,1,3};
    int res = trap(A);
    cout<<"Maximum Water Trapped - "<<res<<endl;
    return 0;
}
