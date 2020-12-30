//
//  main.cpp
//  FindMajority
//
//  Created by bsarvan on 14/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc,
    vector<int> V = {1,2,2,1,1,1,3,2,2,2};
    int candidate = 0;
    cout<<"Program to find majority entities in an array in O(n) time and O(1) space"<<endl;
    int i

    while (i<V.size()) {
        if (count  == 0) {
            candidate = V[i];
            count = 1;
        } else if (candidate == V[i]) {
            count++;
        } else {
            count--;
        }
        i++;
    }
    
    cout<<"Majority element is - "<<candidate<<en
    return 0;
}
