//
//  main.cpp
//  GenerateParenthisis
//
//  Created by bsarvan on 09/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
   "()()()"
 ]
 
 */
#include <iostream>
#include <string>
using namespace std;

//void backtrack(string S, int open, int close, int max) {
//    if (S.size() == 2*max) {
//        cout<<"Returning - Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
//        return;
//    }
//
//    cout<<"Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
//    if (open < max) {
//        cout<<"Adding a opening brace ("<<endl;
//        backtrack(S+'(', open+1, close, max);
//    }
//
//    if (close < open) {
//        cout<<"Adding a closing brace )"<<endl;
//        backtrack(S+')', open, close + 1, max);
//    }
//    cout<<"Returning - Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
//
//}


void backtrack(string S, int open, int close, int max) {
    if (S.size() == 2*max) {
        cout<<S<<endl;
        return;
    }
    
    cout<<"Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
    if (open < max) {
        backtrack(S+'(', open+1, close, max);
    }
    
    if (close < open) {
        backtrack(S+')', open, close + 1, max);
    }
}

int main(int argc, const char * argv[]) {
    string p = "((()))";
    
    backtrack("", 0, 0, 3);
    
    return 0;
}
