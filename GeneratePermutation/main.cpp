//
//  main.cpp
//  GeneratePermutation
//
//  Created by bsarvan on 18/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void permute(vector<int> &input, int index, vector<vector<int>> *results) {
    int n = input.size() - 1;
    if (index == n) {
        results->emplace_back(input);
        return;
    }
    
    for (int i = index; i <= n; i++) {
        swap(input[index], input[i]);
        permute(input, index+1, results);
        swap(input[index], input[i]);
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input = {1,2,3, 4};
    
    
    vector<vector<int>> results;
    permute(input, 0, &results);
    for (auto c:results) {
        for (auto b:c) {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
