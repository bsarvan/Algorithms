//
//  main.cpp
//  ValidUTF8
//
//  Created by bsarvan on 18/10/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//



/*
 
 UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.
 
 For example, the Euro sign, €, corresponds to the three bytes 11100010 10000010 10101100. The rules for mapping characters are as follows:
 
 For a single-byte character, the first bit must be zero.
 For an n-byte character, the first byte starts with n ones and a zero. The other n - 1 bytes all start with 10.
 Visually, this can be represented as follows.
 
 Bytes   |           Byte format
 -----------------------------------------------
 1     | 0xxxxxxx
 2     | 110xxxxx 10xxxxxx
 3     | 1110xxxx 10xxxxxx 10xxxxxx
 4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 Write a program that takes in an array of integers representing byte values, and returns whether it is a valid UTF-8 encoding.
 
 */


#include <iostream>
#include <vector>
using namespace std;


bool validate(vector<int> V) {
    int count = 0;
    
    if (V.size() == 0) {
        return false;
    }
    
    int first = V[0];
    
    cout<<hex<<(first>>5)<<endl;
  
    if (first >> 7 == 0) {
        count = 0;
    } else if ((first >> 5) == 6) {
        count = 1;
    } else if ((first >> 4) == 14) {
        count = 2;
    } else if ((first >> 3) == 30) {
        cout<<"Here"<<endl;
        count = 3;
    } else {
        return false;
    }
    
    cout<<"Count - "<<count<<endl;
    
    for (int i = 1; i < V.size(); i++ ) {
        if ((V[i] >> 6) == 2) {
            count--;
        } else {
            return false;
        }
    }
    
    return (count == 0);
    
}


int main(int argc, const char * argv[]) {
    
    vector<int> A = {230,166,134};
    
    bool result = validate(A);
    cout<<"Is the sequence valid "<<result<<endl;
    
    return 0;
}
