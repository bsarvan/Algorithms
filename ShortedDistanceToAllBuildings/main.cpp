//
//  main.cpp
//  ShortedDistanceToAllBuildings
//
//  Created by Bharat Sarvan on 19/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

void printGrid(vector<vector<int>> grid) {
    
    for (auto row:grid) {
        for (auto col:row) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
}

void printVisited(vector<vector<bool>> visited) {
    
    for (auto row:visited) {
        for (auto col:row) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
}

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
        cout<<"Processing cell - "<<cell.x<<","<<cell.y<<endl;
        for (auto dir:dirs) {
            int X = cell.x + dir[0];
            int Y = cell.y + dir[1];
            
            if (isValid(grid, X, Y) && !visited[X][Y]) {
                visited[X][Y] = true;
                dist[X][Y] = cell.step + 1;
                counter[X][Y] += 1;
                Q.emplace(Cell(X,Y, dist[X][Y]));
            }
        }
        cout<<"Distances Grid - "<<endl;
        printGrid(dist);
        cout<<"Counter Grid - "<<endl;
        printGrid(counter);
    }
}


int findShortestDistance(vector<vector<int>> grid) {
    vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> counter(grid.size(), vector<int>(grid[0].size(), 0));
    int numOfBuildings = 0;
    
    for (int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            //Build the distance and counter matrix from each of the buildings in the grid
            if (grid[i][j] == 1) {
                numOfBuildings++;
                cout<<"Finding the distances from building at cell - ("<<i<<", "<<j<<")"<<endl;
                bfs(grid, distance, counter, i, j);
                cout<<"========================================================================"<<endl;
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
    int result = findShortestDistance(grid);
    cout<<"Shortest Distance - "<<result<<endl;
    
    return 0;
}
 

