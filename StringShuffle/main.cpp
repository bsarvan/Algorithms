//
//  main.cpp
//  StringShuffle
//
//  Created by Bharat Sarvan on 03/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 Write a program to convert list ABCDE12345 to A1B2C3D4E5.
 */
#include <iostream>
#include <string>
using namespace std;



int main(int argc, const char * argv[]) {
    string A = "ABCDE12345";
    string result;
    
    size_t mid = A.size() / 2;
    
    int index = 0;
    while(index < A.size() and mid < A.size()) {
        result.push_back(A[index++]);
        result.push_back(A[mid++]);
    }
    
    cout<<result<<endl;
    
    return 0;
}
