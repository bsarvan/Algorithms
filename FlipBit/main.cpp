//
//  main.cpp
//  FlipBit
//
//  Created by Bharat Sarvan on 03/02/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> flip(string S) {
    vector<int> arr(S.size());
    
    for (int i = 0; i < S.size(); i++) {
        arr[i] = S[i] == '1' ? -1 : 1;
    }
    
    pair<int, int> indices = make_pair(INT_MAX, INT_MAX);
    int max_ending_here = 0, max_till_now = 0, l = 0;
    for (int i = 0 ; i < arr.size(); i++) {
        
        if (max_ending_here + arr[i] < 0) {
            l = i + 1;
            max_ending_here = 0;
        } else max_ending_here += arr[i];
        
       
        if (max_ending_here > max_till_now) {
            max_till_now = max_ending_here;
            indices.first = l;
            indices.second = i;
        }
    }
    
    
    if (indices.first == INT_MAX) return {};
    
    vector<int> result;
    result.emplace_back(indices.first + 1);
    result.emplace_back(indices.second + 1);
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    string S = "010";
    
    vector<int> result = FlipToMaximiseOnes(S);
    cout<<"The range of indices which have maximum ones are - ["<<result[0]<<", "<<result[1]<<"]"<<endl;
    
    return 0;
}
