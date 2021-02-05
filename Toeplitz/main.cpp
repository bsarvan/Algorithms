//
//  main.cpp
//  Toeplitz
//
//  Created by bsarvan on 13/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


bool checkDiagonal (vector<vector<int>> M, int row, int col) {
    int val = M[row][col];
    int i = row;
    int j = col;
    
    while(++i<M.size() && ++j<M[0].size()) {
        //cout<<M[i][j]<<",";
        if (M[i][j] != val) {
            return false;
        }
    }
    return true;
    
}


bool is_toeplitz(vector<vector<int>> A) {
//    vector<vector<int>> values(A.size(), vector<int>(A[0].size()));
    
    for (int col = 0;col<A[0].size();col++) {
        int result = checkDiagonal(A, 0, col);
        if (!result) {
            return false;
        }
    }
    
    for (int row = 1; row<A.size();row++) {
        int result = checkDiagonal(A, row, 0);
        if (!result) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> A = {{1,2,3,4},
                             {6,1,2,3},
                             {7,6,1,2}};
    
    string result = is_toeplitz(A) == true? "TRUE":"FALSE";
    
    cout<<"The given matrix is toepltiz - "<<result<<endl;
    return 0;
}
