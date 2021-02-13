//
//  main.cpp
//  RotateMatrix
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


void printVector(vector<vector<int>> mat) {
    for (auto m : mat) {
        for (auto c : m) {
            cout<<c<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void transpose(vector<vector<int>> &mat) {
    for (size_t r = 0; r < mat.size(); r++) {
        for (size_t c = r; c < mat[0].size(); c++) {
            swap(mat[r][c], mat[c][r]);
        }
    }
}


void reverseVector(vector<vector<int>> &mat, size_t row) {
    int low = 0;
    size_t high = mat[0].size() - 1;
    
    while(low <= high) {
        swap(mat[row][low++], mat[row][high--]);
    }
    
    return;
}

int main() {
    
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    cout<<"Input is -"<<endl;
    printVector(mat);
    
    //create a transpose of a matrix
    transpose(mat);
    cout<<"Transposed - "<<endl;
    printVector(mat);
    
    
    for (size_t row = 0; row < mat.size(); row++) {
        reverseVector(mat, row);
    }
    
    cout<<"Rotated Matrix - "<<endl;
    printVector(mat);
    
    
    return 0;
}
