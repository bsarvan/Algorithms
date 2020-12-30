//
//  main.cpp
//  ReverseStringWordsWithDelimeters
//
//  Created by Bharat Sarvan on 28/11/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. For example, given "hello/world:here", return "here/world:hello"

 Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    string S = "abc/cde#jkm";
    vector<char> delimeters;
    
    for (auto s:S){
        if (!isalpha(s)) {
            delimeters.emplace_back(s);
        }
    }
    
    cout<<"Input String - "<<S<<endl;
    reverse(S.begin(), S.end());
    
    size_t end;
    size_t start = 0;
    size_t i = delimeters.size() - 1;
    int j = 0;
    while((end = S.find(delimeters[i], start)) != string::npos) {
        reverse(S.begin() +  start, S.begin() + end);
        S[end] = delimeters[j];
        
        start = end + 1;
        j++;
        i--;
    }
    
    reverse(S.begin() + start, S.end());
    
    cout<<"Output - "<<S<<endl;
    return 0;
}
    
