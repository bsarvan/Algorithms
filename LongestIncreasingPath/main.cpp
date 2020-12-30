//
//  main.cpp
//  LongestIncreasingPath
//
//  Created by bsarvan on 15/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Longest Increasing Path in a Matrix
 Given an integer matrix, find the length of the longest increasing path.

 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

 Example 1:

 Input: nums =
 [
   [9,9,4],
   [6,6,8],
   [2,1,1]
 ]
 Output: 4
 Explanation: The longest increasing path is [1, 2, 6, 9].
 Example 2:

 Input: nums =
 [
   [3,4,5],
   [3,2,6],
   [2,2,1]
 ]
 Output: 4
 Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
#define MAX 10

// Return the length of LIP in 2D matrix
int LIP(int dp[][MAX], int mat[][MAX], int n, int m, int x, int y)
{
    // If value not calculated yet.
    if (dp[x][y] < 0) {
        int result = 0;

        // If reach bottom left cell, return 1.
        if (x == n - 1 && y == m - 1)
            return dp[x][y] = 1;

        // If reach the corner of the matrix.
        if (x == n - 1 || y == m - 1)
            result = 1;

        // If value greater than below cell.
        if (mat[x][y] < mat[x + 1][y])
            result = 1 + LIP(dp, mat, n, m, x + 1, y);

        // If value greater than left cell.
        if (mat[x][y] < mat[x][y + 1])
            result = max(result, 1 + LIP(dp, mat, n, m, x, y + 1));

        dp[x][y] = result;
    }

    return dp[x][y];
}

// Wrapper function
int wrapper(int mat[][MAX], int n, int m)
{
    int dp[MAX][MAX];
    memset(dp, -1, sizeof dp);

    return LIP(dp, mat, n, m, 0, 0);
}

void printGrid(int mat[][MAX]) {
    
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

// Driven Program
int main()
{
    int mat[][MAX] = {
        { 1, 2, 3, 4 },
        { 2, 2, 3, 4 },
        { 3, 2, 3, 4 },
        { 4, 5, 6, 7 },
    };
    int n = 4, m = 4;
    cout << wrapper(mat, n, m) << endl;

    return 0;
}
