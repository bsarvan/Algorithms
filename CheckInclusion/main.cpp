//
//  main.cpp
//  CheckInclusion
//
//  Created by bsarvan on 29/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 LeetCode
 
 Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

  

 Example 1:

 Input: s1 = "ab" s2 = "eidbaooo"
 Output: True
 Explanation: s2 contains one permutation of s1 ("ba").
 Example 2:

 Input:s1= "ab" s2 = "eidboaoo"
 Output: False
  

 Note:

 The input strings only contain lower case letters.
 The length of both given strings is in range [1, 10,000].
 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//class Solution {
//public:
//
//
//    bool matches(vector<int> m1, vector<int> m2) {
//        for (int i = 0; i < m1.size(); i++) {
//            if (m1[i] != m2[i]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool checkInclusion(string s1, string s2) {
//        vector<int> s1_map(26, 0);
//        vector<int> s2_map(26, 0);
//
//        //Build the maps for s1 and s2
//        for (int i = 0; i < s1.size(); i++) {
//            s1_map[s1[i] - 'a']++;
//            s2_map[s2[i] - 'a']++;
//        }
//
//
//        for (int i = s1.length(); i < s2.length(); i++) {
//            if (matches(s1_map, s2_map)) {
//                return true;
//            } else {
//                s2_map[s2[i - s1.length()] - 'a']--;
//                s2_map[s2[i] - 'a']++;
//            }
//        }
//
//        return matches(s1_map, s2_map);
//    }
//};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        
        // If s1 search string is smaller than s2, return false
        if(len1 > len2) return false;
        
        // To hold the frequency count of characters
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        
        // Compute the character frequency for the initial window
        for (int i = 0; i < len1; i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }
        
        // Compute and Compare the maps for a window of len2 - len1 characters from s2;
        for(int i = 0; i < len2 - len1; i++){
            if(map2 == map1) return true;
            map2[s2[i] - 'a']--;
            map2[s2[i + len1] - 'a']++;
        }
        
        // Comparing the map for the last window in s2
        return map1 == map2;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    string s1 = "abc";
    string s2 = "dcba";
    Solution sol;
    
    string result = sol.checkInclusion(s1, s2)? "YES":"FALSE";
    cout<<result<<endl;
    
    return 0;
}
