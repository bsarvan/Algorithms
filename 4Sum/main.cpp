//
//  main.cpp
//  4Sum
//
//  Created by Bharat Sarvan on 14/07/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


vector<int> TwoSum(vector<int> V, int start, int end, int target) {
    vector<int> result;
    
    if (start < 0 || end >= V.size()) {
        return {};
    }
    
    while(start < end) {
        int sum = V[start] + V[end];
        if (sum < target || V[start] == V[start - 1]) {
            start++;
        } else if (sum > target || V[end] == V[end+1]) {
            end--;
        } else {
            result.emplace_back(V[start]);
            result.emplace_back(V[end]);
            break;
        }
    }
    
    return result;
}

vector<vector<int>> FourSum(vector<int> V, int target) {
    
    if (V.size() < 4 || V.empty()) {
        return {{}};
    }
    
    vector<vector<int>> result;
    
    sort(V.begin(), V.end());
    
    for (int i = 0; i < V.size() - 3, i++) {
        for (int j = i + 1;j<V.size() - 2;j++) {
            vector<int> tmp = TwoSum(V, j+1, V.size() - 1, target);
            if (!tmp.empty()) {
                result.emplace_back(vector<int>{V[i], V[j], tmp[0], tmp[1]});
            }
        }
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to compute the 4 sum from a stream of numbers"<<endl;
    
    vector<int> num = {1, 0, -1, 0, -2, 2};
    
    return 0;
}
