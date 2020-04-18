//
//  main.cpp
//  GenerateParenthisis
//
//  Created by bsarvan on 09/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void backtrack(string S, int open, int close, int max) {
    if (S.size() == 2*max) {
        cout<<"Returning - Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
        return;
    }
    
    cout<<"Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
    if (open < max) {
        cout<<"Adding a opening brace ("<<endl;
        backtrack(S+'(', open+1, close, max);
    }
    
    if (close < open) {
        cout<<"Adding a closing brace )"<<endl;
        backtrack(S+')', open, close + 1, max);
    }
    cout<<"Returning - Open - "<<open<<", Close - "<<close<<", Braces - "<<S<<endl;
    
}


int main(int argc, const char * argv[]) {
    string p = "((()))";
    
    backtrack("", 0, 0, 3);
    
    return 0;
}
