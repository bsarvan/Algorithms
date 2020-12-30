//
//  main.cpp
//  MinimumSwap
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int> A) {
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    int swap = 0;
    
    unordered_map<int, int> index_map;
    for (int i = 0; i < A.size(); i++) {
        index_map.emplace_back(A[i], i);
    }
    
    for (int i = 0; i < A.size(); i++) {
        int correct_value = sorted_A[i];
        if (A[i] != correct_value) {
            int to_swap_index = index_map[correct_value];
            swap(A[i], A[to_swap_index]);
            index_map[v] = to_swap_index;
            index_map[correct_value] = i;
            
            swap++;
            
        }
    }
    
    return swap;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
