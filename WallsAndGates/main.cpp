//
//  main.cpp
//  WallsAndGates
//
//  Created by bsarvan on 21/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <vector>
#include <queue>

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

const int INF = 2147483647;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        
        int row = rooms.size();
        int col = rooms[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto pr = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = pr.first + dr[i];
                int nc = pr.second + dc[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && rooms[nr][nc] == INF) {
                    q.push({nr, nc});
                    rooms[nr][nc] = rooms[pr.first][pr.second] + 1;
                }
            }
        }
        return;
    }
};


int main(int argc, char** argv) {
    return 0;
}

