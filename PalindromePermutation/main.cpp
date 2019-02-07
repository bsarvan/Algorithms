//
//  main.cpp
//  PalindromePermutation
//
//  Created by bsarvan on 01/02/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<char,int> BuildFreqTable(string A){
    unordered_map<char,int> C;
    
    for(char c:A){
        C[c]++;
    }
    return C;
    
}

int main(int argc, const char * argv[]) {
    
    cout<<"Test program to calculate the character frequency count."<<endl;
    string s = "abababa";
    unordered_map<char,int> M = BuildFreqTable(s);
    
    bool oddCount = false;
    for(auto c:M) {
        if (c.second % 2 == 1) {
            if (oddCount == true) {
                cout<<"More than one odd characters"<<endl;
                break;
            }
            oddCount = true;
        }
    }
    
    
    return 0;
}
