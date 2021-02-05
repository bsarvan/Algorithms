//
//  main.cpp
//  GeneratePowerSet
//
//  Created by Bharat Sarvan on 18/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


vector<vector<char>> generatePowerSet(vector<char> input) {
    vector<vector<char>> result;
    
    for(int i = 0; i < (1 << input.size()); i++) {
        int bit_param = i;
        
        vector<char> temp_result;
        while(bit_param) {
            temp_result.emplace_back(input[log2(bit_param & ~(bit_param - 1))]);
            bit_param &= (bit_param - 1);
        }
        
        result.emplace_back(temp_result);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to generate power set of characters in a vector using bitvector"<<endl;
    vector<char> input = {'a','b','c','d'};
    
    vector<vector<char>> result = generatePowerSet(input);
    
    for (auto vec : result) {
        for (auto v : vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}
