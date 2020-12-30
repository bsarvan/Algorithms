//
//  main.cpp
//  SmallestSubstringWithUniqueCharacters
//
//  Created by Bharat Sarvan on 28/10/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


string smallestDistintSubstring(string S) {
    vector<int> visited(256, 0);
    vector<int> characters(256, 0);
    int total_distinct = 0;
    // Count the total number of distinct characters in the input string
    for (auto s:S) {
        if (visited[s] == 0) {
            visited[s]++;
            total_distinct++;
        }
    }
    
    cout<<"Total Distinct characters - "<<total_distinct<<endl;
    
    int distinct = 0;
    int start = 0;
    int minLen = INT_MAX;
    int start_index = 0;
    
    for (int i = 0; i < S.size(); i++) {
        
        characters[S[i]]++;
        
        if (characters[S[i]] == 1) {
            distinct++;
        }
        
        
        if (distinct == total_distinct) {
            cout<<"Distinct characters found at index - "<<i<<endl;
            while(characters[S[start]] > 1) {
                cout<<"Moving start index to right"<<endl;
                characters[S[start]]--;
                start++;
            }
            cout<<"Moved start to index - "<<start<<endl;
            int len = i - start + 1;
            if (len < minLen) {
                minLen = len;
                start_index = start;
            }
        }
    }
    
    cout<<"Len - "<<minLen<<endl;
    return S.substr(start_index, minLen);
        
}

int main () {
    string result = smallestDistintSubstring("jiujitsu");
    cout<<result<<endl;
    return 0;
}
