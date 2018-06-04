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


void BuildFreqTable(string A){
    unordered_map<char,int> C;
    
    for(char c:A){
        C[c]++;
    }
    
}

int main(int argc, const char * argv[]) {
    
    cout<<"Test program to calculate the character frequency count."<<endl;
    string s = "Bharat Sarvan";
    
    return 0;
}
