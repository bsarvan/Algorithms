//
//  main.cpp
//  PrintAllSubsequences
//
//  Created by Bharat Sarvan on 09/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void subsequence(string S, int bitmap) {
    string sub;
    
    // Optimal solution to pick the characters of a string based only on the bit set
    while(bitmap) {
        sub += S[log2(bitmap & ~(bitmap - 1))];
        bitmap &= bitmap - 1;
    }

    
//    Not a optimal solution to find the bits and pick the characters of the string
//    for (int i = 0; i < S.size(); i++) {
//        if (bitmap & 1<<i) {
//            sub += S[i];
//        }
//    }
    cout<<sub<<endl;
}

int main(int argc, const char * argv[]) {
    cout<<"Algorithm to print all the subsequences of string"<<endl;
    string input = "abcd";
    int len = pow(2, input.size());
    for (int i = 1; i <= len; i++) {
        subsequence(input, i);
    }
    return 0;
}
