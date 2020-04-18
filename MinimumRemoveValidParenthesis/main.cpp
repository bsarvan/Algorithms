//
//  main.cpp
//  MinimumRemoveValidParenthesis
//
//  Created by bsarvan on 21/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given a string s of '(' , ')' and lowercase English characters.

 Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

 Formally, a parentheses string is valid if and only if:

 It is the empty string, contains only lowercase characters, or
 It can be written as AB (A concatenated with B), where A and B are valid strings, or
 It can be written as (A), where A is a valid string.
  

 Example 1:

 Input: s = "lee(t(c)o)de)"
 Output: "lee(t(c)o)de"
 Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 
 
 */
#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> indexesToRemove;
        
        for(int i=0;i<s.size();i++) {
            if (s[i]=='(') {
                st.emplace(i);
            }
            if (s[i]== ')') {
                if (st.empty()) {
                    indexesToRemove.emplace(i);
                } else
                    st.pop();
            }
        }
        
        while(!st.empty()) {
            cout<<"S Top - "<<st.top()<<endl;
            indexesToRemove.emplace(st.top());
            st.pop();
        }
        
        string result;
        for(int i=0;i<s.size();i++) {
            if (indexesToRemove.find(i) == indexesToRemove.end()) {
                result +=s[i];
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    Solution obj;
    string res = obj.minRemoveToMakeValid("l(e(e(t(c)o)de)");
    cout<<res<<endl;
    return 0;
}
