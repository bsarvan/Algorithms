//
//  main.cpp
//  LongestSubsequence
//
//  Created by bsarvan on 30/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> C) {
    
    for(auto c:C) {
        for (auto a:c) {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int LongestCommonSubsequence(string S1, string S2) {
    size_t len1 = S1.size();
    size_t len2 = S2.size();
    
    vector<vector<int>> C(len1 + 1,vector<int>(len2 + 1,0));
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (S1[i-1] == S2[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = max(C[i-1][j], C[i][j-1]);
            }
        }
    }
    
    printMatrix(C);
    
    return C[len1][len2];
}
int main(int argc, const char * argv[]) {
    
    cout<<"Program to find the Longest Common Subsequence"<<endl;
    
    int result = LongestCommonSubsequence("ABCADA", "ABXXC");
    
    cout<<"Length of Longest Common Subsequence - "<<result<<endl;
    return 0;
}
