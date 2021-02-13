//
//  main.cpp
//  RemoveAllDuplicatesArray
//
//  Created by Bharat Sarvan on 30/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> A){
    for(auto a : A) {
        cout<<a<<"  ";
    }
    cout<<endl;
}

vector<int> RemoveAllDuplicates(vector<int> &A) {
    vector<int> result;
    
    for(int i = 0; i < A.size(); i++) {
        cout<<"outer loop"<<endl;
        while(A[i] != A[A[i] - 1]) {
            cout<<"Inner Loop"<<endl;
            swap(A[i], A[A[i] - 1]);
            printVector(A);
        }
    }
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != i + 1) {
            result.emplace_back(A[i]);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {4,3,2,7,8,2,3,1};
    
    vector<int> result = RemoveAllDuplicates(A);
    
    cout<<"Result - "<<endl;
    printVector(result);
    
    return 0;
}
