//
//  main.cpp
//  FindAllAnagrams
//
//  Created by bsarvan on 19/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

 Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

 The order of output does not matter.

 Example 1:

 Input:
 s: "cbaebabacd" p: "abc"

 Output:
 [0, 6]

 Explanation:
 The substring with start index = 0 is "cba", which is an anagram of "abc".
 The substring with start index = 6 is "bac", which is an anagram of "abc".
 Example 2:

 Input:
 s: "abab" p: "ab"

 Output:
 [0, 1, 2]

 Explanation:
 The substring with start index = 0 is "ab", which is an anagram of "ab".
 The substring with start index = 1 is "ba", which is an anagram of "ab".
 The substring with start index = 2 is "ab", which is an anagram of "ab".
 
 */



#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || s.size() < p.size()) return {};

        // Build the character frequency map for pattern
        unordered_map<char, int> mp;
        for (int i = 0; i < p.size(); i++) mp[p[i]] ++;

        int numToFind = p.size(), l = p.size();
        vector<int> resu;
        for (int i = 0; i < s.size(); i++) {
            if (i < l) {
                if (mp.count(s[i])) {
                    if (mp[s[i]] > 0) numToFind --;
                    mp[s[i]] --;
                }
            } else {
                cout<<"Index - "<<i<<endl;
                int start = i - l;
                if (mp.count(s[start])) {
                    if (mp[s[start]] >= 0) numToFind ++;
                    mp[s[start]] ++;
                }
                if (mp.count(s[i])) {
                    if (mp[s[i]] > 0) numToFind --;
                    mp[s[i]] --;
                }
            }
            if (numToFind == 0) resu.push_back(i - l + 1);
        }

        return resu;
    }
};


vector<int> findAnagrams_v2(string S, string p) {
    vector<int> s_map(26, 0);
    vector<int> p_map(26, 0);
    vector<int> result;
    
    //Build the char_count map for characters in S and p
    for (int i = 0; i < p.size(); i++) {
        s_map[S[i] - 'a']++;
        p_map[p[i] - 'a']++;
    }
    
    int i = 0;
    for (i = 0; i <= S.size() - p.size(); i++) {
        if (s_map == p_map) {
            result.emplace_back(i);
        }
        s_map[S[i] - 'a']--;
        s_map[S[i + p.size()] - 'a']++;
    }
    
    if (s_map == p_map) {
        result.emplace_back(i);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find all anagrams in a string"<<endl;
//    Solution sol;
    
    string S = "abab";
    string p = "ab";
    
//    vector<int> result = sol.findAnagrams(S, p);
    vector<int> result = findAnagrams_v2(S, p);
    for (auto i:result) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
