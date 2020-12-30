//
//  main.cpp
//  ShortestDistanceFromBuildings
//
//  Created by Bharat Sarvan on 02/11/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution {
public:
   int shortestDistance(vector<vector<int>>& grid) {
      int ret = INT_MAX;
      size_t n = grid.size();
      size_t m = grid[0].size();
      int numberOfOnes = 0;
      vector < vector <int> > dist(n, vector <int>(m));
      vector < vector <int> > reach(n, vector <int>(m));
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
               numberOfOnes++;
               queue < pair <int, int> > q;
               q.push({i, j});
               set < pair <int, int> > visited;
               for(int lvl = 1; !q.empty(); lvl++){
                   cout<<"Value of lvl - "<<lvl<<endl;
                  size_t sz = q.size();
                  while(sz--){
                     pair <int, int> curr = q.front();
                     q.pop();
                     int x = curr.first;
                     int y = curr.second;
                     for(int k = 0; k < 4; k++){
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited.count({nx, ny}) || grid[nx][ny] != 0) continue;
                        visited.insert({nx, ny});
                        dist[nx][ny] += lvl;
                        reach[nx][ny]++;
                        q.push({nx, ny});
                     }
                  }
               }
            }
         }
      }
       
       
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            if(grid[i][j] == 0 && reach[i][j] == numberOfOnes){
               ret = min(ret, dist[i][j]);
            }
         }
      }
      return ret == INT_MAX ? -1 : ret;
   }
};


int main(int argc, const char * argv[]) {
    cout<<"Algorithm to find the shortest distance from all the buildings"<<endl;
    vector<vector<int>> grid = {{1,0,2,0,1},
                                {0,0,0,0,0},
                                {0,0,1,0,0}};
    
    Solution sol;
    
    int result = sol.shortestDistance(grid);
    
    cout<<"Shortest Distance from all buildings "<<result<<endl;
    return 0;
}
