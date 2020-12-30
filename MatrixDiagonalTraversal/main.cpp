//
//  main.cpp
//  MatrixDiagonalTraversal
//
//  Created by bsarvan on 10/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Problem Statement - Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
 

 
 Each diagonal is just a collection of points (i,j) that satisfy i+j=k, for some constant k. For the top-left diagonal, k=0. For the bottom-right diagonal, k=m+n-2. So we just loop through the possible values of k.
 
 To print each diagonal, we just loop through the possible values of i and print the value at (i,k-i), since j=k-i. The starting and ending values of i are determined by the combination of the following inequalities:
 
 i >= 0,
 i <= m-1,
 k-i >= 0,
 k-i <= n-1.
 
 A simple rearrangement gives:
 
 max(0, k-n+1) <= i <= min(m-1, k).
 
 We switch the loop direction as we go through the diagonals.
 
 */
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return {};
    }
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> r;
    r.reserve(m * n);
    for (int k = 0; k <= m + n - 2; k++) {
        const int start = max(0, k - n + 1);
        const int end = min(m - 1, k);
        cout<<"k - "<<k<<", Start - "<<start<<", End - "<<end<<endl;
        if ((k % 2) == 0) {
            for (int i = end; i >= start; i--) {
                r.push_back(matrix[i][k - i]);
            }
        }
        else {
            for (int i = start; i <= end; i++) {
                r.push_back(matrix[i][k - i]);
            }
        }
    }
    return r;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> M = {{1,2,3},
                             {4,5,6},
                             {7,8,9}};
    cout<<"Testing diagonal traversal of matrix"<<endl;
    
    vector<int> result = findDiagonalOrder(M);
    
    cout<<"Output - ";
    for(auto c:result) {
        cout<<c<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
