//
//  main.cpp
//  ShortestDistance
//
//  Created by bsarvan on 31/03/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 
 You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

 Each 0 marks an empty land which you can pass by freely.
 Each 1 marks a building which you cannot pass through.
 Each 2 marks an obstacle which you cannot pass through.
 Example:

 Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

 1 - 0 - 2 - 0 - 1
 |   |   |   |   |
 0 - 0 - 0 - 0 - 0
 |   |   |   |   |
 0 - 0 - 1 - 0 - 0

 Output: 7

 Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
              the point (1,2) is an ideal empty land to build a house, as the total
              travel distance of 3+3+1=7 is minimal. So return 7.
 
 
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
    
public:
    void printGrid(vector<vector<int>> G) {
        for (auto g:G) {
            for (auto c:g) {
                cout<<c<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, delta[] = {0, 1, 0, -1, 0};
        int mindist = -1;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    mindist = -1;
                    int count = 0;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (q.size()) {
                        auto ij = q.front();
                        //cout<<"Processing cell - ["<<ij.first<<", "<<ij.second<<"]"<<endl;
                        q.pop();
                        // Traverse in all four directions
                        for (int d=0; d<4; ++d) {
                            int i = ij.first + delta[d];
                            int j = ij.second + delta[d+1];
                            //cout<<"Walk :  "<<walk<<endl;
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                                //cout<<"Grid - "<<grid[i][j]<<endl;
//                                cout<<"Traversing cell - ["<<i<<", "<<j<<"]"<<endl;
                                grid[i][j]--;
                                dist[i][j] = dist[ij.first][ij.second] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.emplace(i, j);
                                if (mindist < 0 || mindist > total[i][j])
                                    mindist = total[i][j];
                            }
                        }
//                        cout<<"==========================="<<endl;
//                        cout<<"Dist Grid - "<<endl;
//                        printGrid(dist);
//                        cout<<"Original Grid - "<<endl;
//                        printGrid(grid);
//
                        count++;
                    }
                    cout<<"Processed - "<<count<<" Nodes"<<endl;
                    walk--;
                }
            }
        }
        return mindist;
    }
};

void printGrid(vector<vector<int>> G) {
    for (auto g:G) {
        for (auto c:g) {
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return;
}

void shortestDistanceHelper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dist, vector<vector<int>> &reach, vector<vector<int>> &visited, vector<vector<int>> &total) {
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int, int>> Q;
    
    Q.emplace(row , col);
    while(!Q.empty()) {
        auto cell = Q.front();
        Q.pop();
        
        for(int i=0;i<dir.size();i++) {
            int x = cell.first + dir[i][0];
            int y = cell.second + dir[i][1];
            
            if (x >=0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] == 0) {
                dist[x][y] = dist[cell.first][cell.second] + 1;
                total[x][y] += dist[x][y];
                reach[x][y] += 1;
                visited[x][y] = true;
                Q.emplace(x,y);
            }
        }
    }
}


int shortestDistance(vector<vector<int>> grid) {
    if (grid.empty()) {
        return 0;
    }

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m,vector<int>(n,0));
    vector<vector<int>> reach(m,vector<int>(n,0));
    vector<vector<int>> total(m,vector<int>(n,0));
    
    int numBuildings = 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            vector<vector<int>> visited(m,vector<int>(n,0));
            if (grid[i][j] == 1) {
                shortestDistanceHelper(i, j , grid, dist, reach, visited, total);
                numBuildings++;
            }
        }
    }
    
    cout<<"Number of Buildings in the grid - "<<numBuildings<<endl;
    
    cout<<"Distance Grid - "<<endl;
    printGrid(dist);
    printGrid(reach);
    int minDist = INT_MAX;
    for (int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if (grid[i][j] == 0 && reach[i][j] == numBuildings) {
                minDist = min(minDist, total[i][j]);
            }
        }
    }
    return minDist;
}



struct Cell {
    int x;
    int y;
    int step;
    
    Cell(int x1, int y1, int step1) {
        x = x1;
        y = y1;
        step = step1;
    }
};


bool isValid(vector<vector<int>> grid, int row, int col) {
    return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 0);
}

void bfs(vector<vector<int>> grid, vector<vector<int>> &dist, vector<vector<int>> &counter, int row, int col) {
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    queue<struct Cell> Q;
    
    struct Cell cell(row,col,0);
    visited[row][col] = true;
    dist[row][col] = 0;
    Q.emplace(cell);
    
    while(!Q.empty()) {
        struct Cell cell = Q.front();
        Q.pop();
        for (auto dir:dirs) {
            int X = cell.x + dir[0];
            int Y = cell.y + dir[1];
            
            if (isValid(grid, X, Y) && !visited[X][Y]) {
                visited[X][Y] == false;
                dist[X][Y] = cell.step + 1;
                counter[X][Y] += 1;
                Q.emplace(Cell(X,Y, dist[X][Y]));
            }
        }
    }
}


int findShortestDistance(vector<vector<int>> grid) {
    vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> count(grid.size(), vector<int>(grid[0].size(), 0));
    int numOfBuildings = 0;
    
    for (int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                numOfBuildings++;
                bfs(grid, distance, count, i, j);
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find the Shorted Distance from all buildings"<<endl;
    
    vector<vector<int>> grid = {{1,0,2,0,1},
                                {0,0,0,0,0},
                                {0,0,1,0,0}};
    
    cout<<"The input grid - "<<endl;
    printGrid(grid);
//    Solution sol;
    int result = shortestDistance(grid);
    cout<<"Shortest Distance - "<<result<<endl;
    
    return 0;
}
 

