//
//  main.cpp
//  ShortestDistanceFromAllBuildings
//
//  Created by bsarvan on 02/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int shortestDistance(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist = 0, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
              
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    
                    for (int d=0; d<4; ++d) {
                        int i = ij.first + delta[d];
                        int j = ij.second + delta[d+1];
                        
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                            grid[i][j]--; // This is to mark as visited.
                            dist[i][j] = dist[ij.first][ij.second] + 1; // Increment the distance till this node
                            total[i][j] += dist[i][j] - 1;
                            cout<<"Distance at "<<i<<" , "<<j<<" - "<<dist[i][j]<<", Total - "<<total[i][j]<<endl;
                            q.emplace(i, j); 
                            if (mindist < 0 || mindist > total[i][j])
                                mindist = total[i][j];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to find place to build, with shortest distance to all buildings"<<endl;
    vector<vector<int>> grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    
    int result = shortestDistance(grid);
    cout<<"Shorted Distance "<<result<<endl;
    return 0;
}
