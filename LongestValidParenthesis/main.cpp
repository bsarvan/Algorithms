//
//  main.cpp
//  LongestValidParenthesis
//
//  Created by bsarvan on 19/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 Example 1:

 Input: "(()"
 Output: 2
 Explanation: The longest valid parentheses substring is "()"
 Example 2:

 Input: ")()())"
 Output: 4
 Explanation: The longest valid parentheses substring is "()()"
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int longestValidParenthesisDP(string S) {
    vector<int> dp(S.size(),0);
    int maxLen = INT_MIN;
    
    for (int i=1;i<S.size();i++) {
        if (S[i] == ')') {
            if (S[i-1] == '('){
                dp[i] = (i>=2?dp[i-2]:0) + 2;
            } else if (i - dp[i-1] > 0 && S[i - dp[i] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}


int longestValidParentisUsingStack(string S) {
    stack<int> stack;
    int maxLen = INT_MIN;
    
    for (int i=0;i<S.size();i++) {
        if (S[i] == '(') {
            cout<<"Pushing 1 - "<<i<<endl;
            stack.push(i);
        } else if (!stack.empty()){
            stack.pop();
            if (stack.empty()) {
                cout<<"Pushing 2 - "<<i<<endl;
                stack.push(i);
            } else {
                cout<<"Not Pushing on Stack "<<i<<endl;
                maxLen = max(maxLen, i - stack.top());
            }
        }
                
    }
    return maxLen;
}


int longestValidParenthesesNoExtraSpace(string s) {
    
    int left = 0, right = 0, maxlength = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }
    
    left = right = 0;
    
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxlength = max(maxlength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    
    return maxlength;
}


int main(int argc, const char * argv[]) {
    
    std::cout << "Algorithm to find the longest valid parenthesis in a given string\n";
//    int maxlen = longestValidParenthesisDP("())()()");
    int maxlen = longestValidParentisUsingStack("(())");
//    int maxlen = longestValidParenthesesNoExtraSpace("()()(()");
    cout<<"Maximum length of substring with valid parenthesis - "<<maxlen<<endl;
    return 0;
}
