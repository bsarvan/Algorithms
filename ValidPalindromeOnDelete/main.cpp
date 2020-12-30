//
//  main.cpp
//  ValidPalindromeOnDelete
//
//  Created by bsarvan on 21/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

 Example 1:
 Input: "aba"
 Output: True
 Example 2:
 Input: "abca"
 Output: True
 Explanation: You could delete the character 'c'.
 
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidPalindrome(string::iterator s1, string::iterator s2) {
        while(s1<s2) {
            if (*s1 != *s2) {
                return false;
            }
            s1++;
            s2--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        
        while(low < high) {
            if (s[low] != s[high]){
                return (isValidPalindrome(s.begin() + low + 1, s.begin() + high) ||
                        isValidPalindrome(s.begin() + low, s.begin() + high - 1));
            }
            low++;
            high--;
        }
        return true;
    }

};


int main(int argc, const char * argv[]) {
    
    string S = "aabyxaa";
    
    Solution sol;
    
    bool output = sol.validPalindrome(S);
    
    string result = output == true ? "YES" : "FALSE";
    
    cout<<result<<endl;
    return 0;
}

