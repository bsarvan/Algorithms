//
//  main.cpp
//  LengthLongestSubstringWithoutRepeatCharac
//
//  Created by bsarvan on 26/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Example 1:
 
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:
 
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:
 
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 
 
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string S) {
    unordered_map<char, int> mp;
    int maxLen = 0;
    string result;
    
    for (int i = 0; i<S.size();i++) {
        int start = i;
        int index = i;
        int count = 0;
        
        while(index < S.size() && mp[S[index]]==0) {
            mp[S[index]]++;
            index++;
            count++;
        }
        
        mp.clear();
        
        if (count > maxLen) {
            maxLen = count;
            result = S.substr(start, maxLen);
            cout<<"Longest substring without repeating character is of length - "<<maxLen<<", String - "<<result<<endl;
        }
    }
    return maxLen;
}


int lengthOfLongestSubstringV2(string S) {
    unordered_set<char> st;
    int ans = 0;
    int i=0;
    int j=0;
    size_t n = S.size();
    
    while(i<n && j < n) {
        if (st.find(S[j]) == st.end()) {
            st.emplace(S[j++]);
            ans = max(ans, j - i);
        } else {
            st.erase(S[i++]);
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    string S = "abcabcbb";

    int result = lengthOfLongestSubstringV2(S);
    cout<<"Length of the longest substring with no repeating characters - "<<result<<endl;
    return 0;
}
