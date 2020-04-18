//
//  main.cpp
//  ShortestDistance
//
//  Created by bsarvan on 31/03/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

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

void shortestDistanceHelper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dist, vector<vector<int>> &reach, vector<vector<int>> &visited) {
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
                cout<<"Dist Grid - "<<endl;
                printGrid(dist);
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
    int numBuildings = 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            vector<vector<int>> visited(m,vector<int>(n,0));
            if (grid[i][j] == 1) {
                shortestDistanceHelper(i, j , grid, dist, reach, visited);
                numBuildings++;
            }
        }
    }
    
    cout<<"Number of Buildings in the grid - "<<numBuildings<<endl;
    
    int minDist = INT_MAX;
    for (int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if (grid[i][j] == 0 && reach[i][j] == numBuildings) {
                minDist = min(minDist, dist[i][j]);
            }
        }
    }
    return minDist;
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
