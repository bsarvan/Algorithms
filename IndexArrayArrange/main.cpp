//
//  main.cpp
//  IndexArrayArrange
//
//  Created by Bharat Sarvan on 01/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 Problem:
 Given array of size N, containing elements from 0 to N-1.
 All values from 0 to N-1 are present in array and if they are not there than -1 is there to take its place.
 Arrange values of array so that value i is stored at arr[i].
 
 Input: [8, -1, 6, 1, 9, 3, 2, 7, 4, -1] Output: [-1, 1, 2, 3, 4, -1, 6, 7, 8, 9]
 
 */
#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> arr) {
    for (auto a : arr) {
        cout<<a<<" ";
    }
    cout<<endl;
}

void IndexArray(vector<int> &A) {
    
    for (int i = 0; i < A.size(); i++) {
        int curr = i;
        int value = -1;
        
        while(A[curr] != -1 and A[curr] != curr) {
            int temp = A[curr];
            A[curr] = value;
            value = curr = temp;
            
            printVector(A);
        }
        
        if (value != -1) {
            A[curr] = value;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Algorithm to arrange values in array so that value i is stored at A[i]"<<endl;
    
    vector<int> input = {8, -1, 6, 1, 9, 3, 2, 7, 4, -1};
    
    IndexArray(input);
    
    cout<<"Result - ";
    for (auto &elem : input) {
        cout<<elem<<" ";
    }
    cout<<endl;
    return 0;
}
