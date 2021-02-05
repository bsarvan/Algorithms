//
//  main.cpp
//  ArrayReduction
//
//  Created by Bharat Sarvan on 24/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 Problem: Element left after reductions. Given an array of positive elements. You need to perform reduction operation. In each reduction operation smallest positive element value is picked and all the elements are subtracted by that value. You need to print the number of elements left after each reduction process.
 
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;


void ArrayReduction_v1(vector<int> arr) {
    set<int> S;
    
    for(auto a : arr) {
        S.emplace(a);
    }
    
    for (auto s : S) {
        vector<int> tmp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] - s > 0) {
                tmp.emplace_back(arr[i] - s);
            }
        }
        if (tmp.size() > 0) cout<<tmp.size()<<endl;
    }
    return;
}
    

void ArrayReduction(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int count = 0;
    int reduction = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] - reduction > 0) {
            cout<<"Reduction - "<<reduction<<", i - "<<i<<endl;
            cout<<arr.size() - i<<endl;
            reduction = arr[i];
            count++;
        }
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr = {5, 1, 1, 1, 2, 3, 5, 6};
    
    ArrayReduction(arr);
    
    ArrayReduction_v1(arr);
    return 0;
}
