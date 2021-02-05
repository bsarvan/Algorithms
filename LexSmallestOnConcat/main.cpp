//
//  main.cpp
//  LexSmallestOnConcat
//
//  Created by Bharat Sarvan on 01/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//


/*
 Lexicographically smallest string obtained after concatenating array
 
 Difficulty Level : Easy
  Last Updated : 21 Jan, 2019
 Given n strings, concatenate them in an order that produces the lexicographically smallest possible string.

 Examples:

 Input :  a[] = ["c", "cb", "cba"]
 Output : cbacbc
 Possible strings are ccbcba, ccbacb,
 cbccba, cbcbac, cbacbc and cbaccb.
 Among all these strings, cbacbc is
 the lexicographically smallest.

 Input :  a[] = ["aa", "ab", "aaa"]
 Output : aaaaaab
 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool compare (string a, string b) {
    return a + b < b + a;
}


string FindLexSmallest(vector<string> words) {
    sort(words.begin(), words.end(), compare);
    
    string result;
    for (auto &word : words) {
        result += word;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the Lexographically Smallest String by Concatenating Strings in an Array"<<endl;
    
    vector<string> words = {"c", "cb", "cba"};
    
    string result = FindLexSmallest(words);
    cout<<"Result - "<<result<<endl;
    return 0;
}
