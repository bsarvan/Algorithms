//
//  main.cpp
//  DecodeWays
//
//  Created by bsarvan on 12/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given a non-empty string containing only digits, determine the total number of ways to decode it.

 The answer is guaranteed to fit in a 32-bit integer.

  

 Example 1:

 Input: s = "12"
 Output: 2
 Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 Example 2:

 Input: s = "226"
 Output: 3
 Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 Example 3:

 Input: s = "0"
 Output: 0
 Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
 */

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
    cout<<"K - "<<k<<endl;
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
    int result = decodeWays("229");
    cout<<"Decode Ways - "<<result<<endl<<endl;
    return 0;
}
