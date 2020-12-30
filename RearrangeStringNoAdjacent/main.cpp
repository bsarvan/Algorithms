//
//  main.cpp
//  RearrangeStringNoAdjacent
//
//  Created by Bharat Sarvan on 18/08/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.
 For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
 */

#include <iostream>
#include <string>
using namespace std;

void rearrange(string S) {
    
    for (int i=1;i<S.size();i++) {
        if (S[i-1] == S[i]) {
            int j = i;
            while(S[j]==S[i] && j<S.size()) {
                j++;
            }
            swap(S[j],S[i]);
        }
    }
    
    cout<<S<<endl;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to re-arrange characters in a string so that no two repeated characters are adjacent"<<endl;
    string str = "aaaabbc";
    rearrange(str);
    
    return 0;
}
