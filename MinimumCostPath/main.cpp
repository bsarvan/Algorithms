//
//  main.cpp
//  MinimumCostPath
//
//  Created by bsarvan on 25/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ROW 3
#define COL 4

struct cell {
    int x,y;
    int distance;
    
    cell(int x, int y, int distance):x(x), y(y), distance(distance) {}
    
    bool operator<(const cell &b) const {
        if (this->distance == b.distance) {
            if (this->x != b.x) {
                return (this->x < b.x);
            } else {
                return (this->y < b.y);
            }
        }
        return (this->distance < b.distance);
    }
};

//bool operator<(const cell &a, const cell &b) {
//    if (a.distance == b.distance) {
//        if (a.x != b.x) {
//            return (a.x < b.x);
//        } else {
//            return (a.y < b.y);
//        }
//    } else {
//        return a.distance < b.distance;
//    }
//}

// Utility method to check whether a point is
// inside the grid or not
bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i < ROW && j >= 0 && j < COL);
}


void printObject(struct cell k) {
    cout<<"("<<k.x<<","<<k.y<<","<<k.distance<<")"<<endl;
}


void printDistance(int dis[ROW][COL]) {
    for (int i = 0; i < ROW; i++, cout << endl)
        for (int j = 0; j < COL; j++)
            cout << dis[i][j] << " ";
    
    return;
}

void printSet(set<struct cell> s) {
    set<struct cell> :: iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        // print in ascending order as required.
        printObject(*it);
    }
    cout<<"============================="<<endl;
    
}


// Method returns minimum cost to reach bottom
// right from top left
int shortest(int grid[ROW][COL], int row, int col)
{
    int dis[row][col];
  
    // initializing distance array by INT_MAX
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            dis[i][j] = INT_MAX;
  
    // direction arrays for simplification of getting
    // neighbour
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
  
    set<struct cell> st;
  
    // insert (0, 0) cell with 0 distance
    st.insert(cell(0, 0, 0));
  
    //printSet(st);
    
    // initialize distance of (0, 0) with its grid value
    dis[0][0] = grid[0][0];
  
    // loop for standard dijkstra's algorithm
    while (!st.empty())
    {
        printSet(st);
        // get the cell with minimum distance and delete
        // it from the set
        cell k = *st.begin();
        st.erase(st.begin());
        
        cout<<"Find Distance from  - ";
        printObject(k);

        // looping through all neighbours
        for (int i = 0; i < 4; i++)
        {
            int x = k.x + dx[i];
            int y = k.y + dy[i];
  
            // if not inside boundary, ignore them
            if (!isInsideGrid(x, y))
                continue;
  
            // If distance from current cell is smaller, then
            // update distance of neighbour cell
            if (dis[x][y] > dis[k.x][k.y] + grid[x][y])
            {
                // If cell is already there in set, then
                // remove its previous entry
                if (dis[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));
  
                // update the distance and insert new updated
                // cell in set
                dis[x][y] = dis[k.x][k.y] + grid[x][y];
                cout<<"Inserting - "<<x<<" "<<y<<" "<<dis[x][y]<<endl;
                st.insert(cell(x, y, dis[x][y]));
            }
            for (int i = 0; i < row; i++, cout << endl)
                for (int j = 0; j < col; j++)
                    cout << dis[i][j] << " ";
            
            cout<<"========================================================="<<endl;
        }
    }
  
    // uncomment below code to print distance
    // of each cell from (0, 0)
    
    for (int i = 0; i < row; i++, cout << endl)
        for (int j = 0; j < col; j++)
            cout << dis[i][j] << " ";
    
    // dis[row - 1][col - 1] will represent final
    // distance of bottom right cell from top left cell
    return dis[row - 1][col - 1];
}
  
// Driver code to test above methods
int main()
{
//    int grid[ROW][COL] =
//    {
//        31, 100, 65, 12, 18,
//        10, 13, 47, 157, 6,
//        100, 113, 174, 11, 33,
//        88, 124, 41, 20, 140,
//        99, 32, 111, 41, 20
//    };
    
    int grid[ROW][COL] =
    {
        1, 2, 4, 12,
        4, 1, 5, 6,
        2, 3, 7, 9
    };

  
    cout << shortest(grid, ROW, COL) << endl;
    return 0;
}
