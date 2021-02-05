//
//  main.cpp
//  SubsequenceOfString
//
//  Created by bsarvan on 13/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Implement a function that prints all possible combinations of the characters in a string.
 These combinations range in length from one to the length of the string. Two combinations
 that differ only in ordering of their characters are the same combination.
 In other words, “12” and “31” are different combinations from the input string “123”, but “21” is the same as “12”.
 */


#include <iostream>
#include <string>
using namespace std;

void powerSet(string S, int index=0, string curr = "") {
    size_t n = S.length();
    
    cout<<curr<<endl;
    
    if (index == n) {
        return;
    }
    

    for (int i = index; i < n; i++) {
        curr+=S[i];
        powerSet(S,i + 1,curr);
        curr.erase(curr.size() - 1);
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to find the subsequence of string"<<endl;
    string str = "abc";
    powerSet(str);
    return 0;
}
