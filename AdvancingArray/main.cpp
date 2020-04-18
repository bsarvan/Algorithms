//
//  main.cpp
//  AdvancingArray
//
//  Created by bsarvan on 03/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> A = {2,1,0,2,0,2,0,1};
    
    size_t last_index = A.size() - 1;
    bool can_reach_end = false;
    
    cout<<"Program to check if the end of array can be reached"<<endl;
    
    int max_so_far = 0;
    
    for (int i = 0; i <= max_so_far && max_so_far < last_index ; i++) {
        max_so_far = max(max_so_far, i + A[i]);
        cout<<max_so_far<<" ";
    }
    
    cout<<endl;
    
    can_reach_end = max_so_far >= last_index;
    string result = can_reach_end == true? "True":"False";
    cout<<"Can reach end  - "<<result<<endl;
    
    return 0;
}
