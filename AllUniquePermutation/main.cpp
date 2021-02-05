//
//  main.cpp
//  AllUniquePermutation
//
//  Created by bsarvan on 19/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
 Write a method to compute all permutations of a string whose characters are not necessarily unique. The list of permutations should not have duplicates.
 */

void buildDinstinctPermutationsHelper(unordered_map<char, int> map, string prefix, size_t remaining, vector<string> &result) {
    if (remaining == 0) {
        result.emplace_back(prefix);
        return;
    }
    
    for (auto mp:map) {
        int count = mp.second;
        if (count > 0) {
            mp.second = count - 1;
            buildDinstinctPermutationsHelper(map, prefix + mp.first, remaining - 1, result);
            mp.second = count + 1;
        }
    }
}


vector<string> buildDinstinctPermutations(string S) {
    unordered_set<string> string_set;
    vector<string> result;

    buildDinstinctPermutationsHelper(charFreqTable, "", S.size(), result);
    
    return result;
}



class Solution {
    void permuteUtil(vector<int> &A, int l, set<vector<int>> &s, vector<vector<int>> &result) {
        int n = A.size() - 1;
        if ( l == n) {
            if (s.find(A) == s.end()) {
                s.emplace(A);
                result.emplace_back(A);
            }
            return;
        }

        for (int i = l;i<=n;i++) {
            if ((i==l) || (A[i] != A[l])) {
                swap(A[l], A[i]);
                permuteUtil(A, l+1, s, result);
                swap(A[l],A[i]);
            }
        }

        return;
    }
public:
    
    
    vector<vector<int>> permuteUnique(vector<int>& A) {
        vector<vector<int>> result;
        set<vector<int>> S;

        permuteUtil(A,0,S,result);
        return result;
    }
};





int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to compute distinct permutation from string with duplicate characters"<<endl;
    string input = "aab";
    
    vector<string> result = buildDinstinctPermutations(input);
    for (auto r:result) {
        cout<<r<<endl;
    }
    return 0;
}
