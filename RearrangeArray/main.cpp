//
//  main.cpp
//  RearrangeArray
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



int main(int argc, const char * argv[]) {
    vector<int> A = {4, 0, 2, 1, 3};
    vector<int> result;
    
    for (int i = 0; i < A.size(); i++) {
        result.emplace_back(A[A[i]]);
    }
    
    for (auto r:result) {
        cout<<r<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
