//
//  main.cpp
//  BreakUpAString
//
//  Created by Bharat Sarvan on 21/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//


/*
 This problem was asked by Amazon.

 Given a string s and an integer k, break up the string into multiple lines such that each line has a length of k or less. You must break it up so that words don't break across lines. Each line has to have the maximum possible amount of words. If there's no way to break the text up, then return null.

 You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.

 For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.
 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> BreakString(string line, int K) {
    if (line.empty()) {
        return {};
    }
    
    if (line.length() < K) {
        return {line};
    }
    
    vector<string> result;
    int start = 0;
    int end = K;
    
    while(end < line.length()) {
        if (end - start == K and line[end + 1] != ' ') {
            while(line[end] != ' ') {
                end--;
            }
            result.emplace_back(line.substr(start, end - start + 1));
            start = end + 1;
        } else if (end == line.length() - 1) {
            result.emplace_back(line.substr(start, end - start + 1));
        }
        end++;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    string line  = "the quick brown fox jumps over the lazy dog";
    string line  = "the quick brown fox jumps over the lazy dog         ";
    int K = 10;
    vector<string> result = BreakString(line, K);
    for(auto r : result) {
        cout<<r<<endl;
    }
    return 0;
}
