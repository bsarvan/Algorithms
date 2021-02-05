//
//  main.cpp
//  OneEditDistance
//
//  Created by Bharat Sarvan on 11/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool oneEditDistance(string A, string B) {
    if (A.empty() || B.empty()) {
        return false;
    }
    
    if (A.size() > B.size()) {
        swap(A, B);
    }
    
    int indexA = 0;
    int indexB = 0;
    bool foundDifference = false;
    
    while(indexA < A.size() and indexB < B.size()) {
        if (A[indexA] != B[indexB]) {
            if (foundDifference == true) {
                return false;
            }
            
            foundDifference = true;
            
            if (A.size() == B.size()) {
                indexA++;
            }
        } else {
            indexA++;
        }
        indexB++;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorith to check if two strings are one character edit distance away"<<endl;
    string A = "palde";
    string B = "paddee";
    
    bool result = oneEditDistance(A, B);
    
    string resultString = result == true? "YES":"FALSE";
    
    cout<<"Is one edit distance away - "<<resultString<<endl;
    
    return 0;
}
