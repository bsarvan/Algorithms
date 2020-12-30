//
//  main.cpp
//  WordBreak
//
//  Created by bsarvan on 13/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 Note:
 
 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:
 
 Input: s = "leetcode", wordDict = ["leet", "code"]
 Output: true
 Explanation: Return true because "leetcode" can be segmented as "leet code".
 Example 2:
 
 Input: s = "applepenapple", wordDict = ["apple", "pen"]
 Output: true
 Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 Note that you are allowed to reuse a dictionary word.
 Example 3:
 
 Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output: false

 
 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there.
 The optimization is to look from current position i back and only substring and do dictionary
 look up in case the preceding position j with dp[j] == true is found.
 */
bool wordBreak_DP(string s, vector<string>& dict) {
    if(dict.size()==0) return false;

    vector<bool> dp(s.size()+1,false);
    dp[0]=true;

    for(int i=1;i<=s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j])
            {
                string word = s.substr(j,i-j);
                if(find(dict.begin(), dict.end(), word)!= dict.end())
                {
                    dp[i]=true;
                    break; //next i
                }
            }
        }
    }

    return dp[s.size()];
}

bool WordBreak(string s, vector<string> &dict) {
    int size = s.size();
    
    if (size == 0) {
        return true;
    }
    
    cout<<"Input String - "<<s<<endl;
    
    for(int i = 1; i<=size; i++) {
        cout<<"Susbstring  - "<<s.substr(0,i)<<" - "<<i<<endl;
        if (find(dict.begin(), dict.end(), s.substr(0,i)) != dict.end() &&
            WordBreak(s.substr(i,size - i), dict)) {
            return true;
        }
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to test WordBreak"<<endl;
    
    vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    
    string S = "catsanddog";
    
    cout<<S.substr(0,2)<<endl;
    
    bool result = WordBreak(S, dict);
    cout<<"Result is "<<result<<endl<<endl;
    
    return 0;
    
}
