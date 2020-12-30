//
//  main.cpp
//  UniquePathsInGrid
//
//  Created by Bharat Sarvan on 22/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 Example :
 There is one obstacle in the middle of a 3x3 grid as illustrated below.

 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.
 
 */

#include <iostream>
#include <vector>
using namespace std;


bool isMoveSafe(int i, int j, vector<vector<int>> &G, vector<vector<bool>> &visited ) {
    return (i >= 0 and j >= 0 and i < G.size() and j < G[0].size() and visited[i][j] == false and G[i][j] == 0);
}

void uniquePathsHelper(vector<vector<int>> &G, int i, int j, vector<vector<bool>> &visited, int &count) {
    
    if (not isMoveSafe(i, j, G, visited)) {
        return;
    }
    
    if (i == G.size() - 1 and j == G[0].size() - 1) {
        count++;
        return;
    }
    
    visited[i][j] = true;
    
    if (i + 1 < G.size() and G[i][j] == 0) {
        uniquePathsHelper(G, i + 1 , j, visited, count);
    }
    
    if (j + 1 < G[0].size() and G[i][j] == 0) {
        uniquePathsHelper(G, i, j + 1, visited, count);
    }
    
    visited[i][j] = false;
}

int uniquePaths(vector<vector<int>> grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int uniquePathsCount = 0;
    
    uniquePathsHelper(grid, 0, 0, visited, uniquePathsCount);
    
    return uniquePathsCount;
}

int main(int argc, const char * argv[]) {
    
    
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    
    cout<<"Algorith to find the Unique Paths to a cell in a grid"<<endl;
    int result = uniquePaths(grid);
    
    cout<<result<<endl;
    
    return 0;
}
