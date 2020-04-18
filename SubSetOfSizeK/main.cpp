//
//  main.cpp
//  SubSetOfSizeK
//
//  Created by bsarvan on 17/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void DirectedCombinations(int n, int k, int offset,
                          vector<int>* partial_output,
                          vector<vector<int>> *result) {
    
    if (partial_output->size() == k) {
        cout<<"Adding to output"<<endl;
        result->emplace_back(*partial_output);
        return;
    }
    
//    const int num_remaining = k - partial_output->size();
//    cout<<"Num remaining - "<<num_remaining<<endl;
//
//    for (int i = offset; i <= n && num_remaining <= n - i + 1; i++) {
    for (int i = offset; i <= n; i++) {
        cout<<"N - i + 1 : "<<n - i + 1<<endl;
        partial_output->emplace_back(i);
        DirectedCombinations(n, k, i + 1, partial_output, result);
        partial_output->pop_back();
    }
    
    cout<<"==============================="<<endl;
    return;
}

vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> result;
    DirectedCombinations(n,k,1, new vector<int>, &result);
    return result;
}




int main(int argc, const char * argv[]) {
    cout<<"Program to generate all subsets of size K"<<endl;
    
    vector<vector<int>> res = combinations(4, 2);
    
    for(int i = 0; i < res.size(); i++ ) {
        for (int j = 0; j < res[0].size(); j++ ) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
