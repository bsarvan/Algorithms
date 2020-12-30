//
//  main.cpp
//  FindNonDuplicate
//
//  Created by Bharat Sarvan on 16/07/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

 For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

 Do this in O(N) time and O(1) space.
 
 */
#include <iostream>
#include <vector>
using namespace std;



void printVector(vector<int> vec) {
    cout<<"Contents of vector - ";
    for(auto v:vec) {
        cout<<v<<" ";
    }
    cout<<endl;
}

int FindUnique(vector<int> V) {
    // Vector of bit position counts
    vector<int> bitVector(32,0);
    
    for (int i=0;i<V.size();i++) {
        // Traverse every bit set in V[i], and increment the bit count in the bitVector
        for (int j=0;j<32;j++) {
            int bit = (V[i] >> j) & 0x1;
            //Mod of 3, since every integer occurs three times.
            bitVector[j] = (bitVector[j] + bit)%3;
        }
        printVector(bitVector);
    }
    
    printVector(bitVector);
    
    int result = 0;
    for (int i=0;i<bitVector.size();i++){
        result += bitVector[i]<<i;
    }
    
    return result;
}



int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the unique number in triplets "<<endl;
    
    vector<int> num = {3,5,3,3};
    
    int number = FindUnique(num);
    
    cout<<"The unique number occurring only once in the vector is "<<number<<endl;
    return 0;
}
