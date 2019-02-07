//
//  main.cpp
//  DecodeWays
//
//  Created by bsarvan on 12/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int decodeWaysHelper(string S, size_t k, int *memo) {
    int result;
    
    if (k == 0 ) {
        return 1;
    }
    
    size_t i = S.size() - k;
    if (S[i] == '0') {
        return 0;
    }
    
    if (memo[k] != 0) {
        return (memo[k]);
    }
    
    result = decodeWaysHelper(S, k-1, memo);
    cout<<"Substring is "<<S.substr(0,2)<<endl;
    if (k>=2 && (stoi(S.substr(0,2))) <=26) {
        result += decodeWaysHelper(S, k-2, memo);
    }
    
    memo[k] = result;
    return result;
    
}
int decodeWays(string S) {
    int *memo = new int[S.size() + 1];
    fill_n(memo, S.size()+1, 0);
    return (decodeWaysHelper(S, S.size(), memo));
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test number of ways to decode a numeric string"<<endl;
    int result = decodeWays("226");
    cout<<"Decode Ways - "<<result<<endl<<endl;
    return 0;
}
