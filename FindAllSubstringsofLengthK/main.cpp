//
//  main.cpp
//  FindAllSubstringsofLengthK
//
//  Created by Bharat Sarvan on 23/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void substringHelper(string S, int l, int k, string curr) {
    if (curr.length() == k) {
        cout<<curr<<endl;
        return;
    }
    
    for (int idx = l; idx < S.length(); idx++) {
        curr += S[idx];
        substringHelper(S, idx, k, curr);
        curr.erase(curr.end() - 1);
    }
}

void GenerateSubStrings(string S, int k) {
    substringHelper(S, 0, k, "");
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find all substrings of length K"<<endl;
    string S = "abcd";
    int K = 2;
    
    GenerateSubStrings(S, K);
    
    return 0;
}
