//
//  main.cpp
//  SearchMaze
//
//  Created by Bharat Sarvan on 10/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef enum { WHITE, BLACK } Color;

struct Coordinate {
    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }
    
    int x, y;
};


bool isValid(Coordinate cur, vector<vector<Color>> maze) {
    return (cur.x < maze.size() && cur.y < maze[0].size() && maze[cur.x][cur.y] == WHITE);
}

bool SearchMazeHelper(Coordinate curr, Coordinate dest, vector<vector<Color>> &maze, vector<Coordinate> &path) {
    
    if (curr == dest) {
        return true;
    }
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    for (const vector<int> &s : dir ) {
        Coordinate next{curr.x + s[0], curr.y + s[1]};
        if (isValid(next, maze)) {
            maze[next.x][next.y] = BLACK;
            path.emplace_back(next);
            if (SearchMazeHelper(next, dest, maze, path)) {
                return true;
            }
            path.pop_back();
        }
        
    }
    
    return false;
}
vector<Coordinate> SearchMaze(vector<vector<Color>> maze, Coordinate s, Coordinate d) {
    vector<Coordinate> path;
    
    maze[s.x][s.y] = BLACK;
    path.emplace_back(s);
    if (SearchMazeHelper(s, d, maze, path)) {
//        path.pop_back();
    }
    
    return path;
}

int main(int argc, const char * argv[]) {
    vector<vector<Color>> maze =  {{WHITE,BLACK,BLACK,WHITE},
                                  {WHITE,WHITE,BLACK,BLACK},
                                  {BLACK,WHITE,WHITE,BLACK},
                                  {BLACK,BLACK,WHITE,WHITE}};
    
    Coordinate source{0,0};
    Coordinate destination{3,3};
    
    vector<Coordinate> path = SearchMaze(maze, source, destination);
    
    for (auto c:path) {
        cout<<"("<<c.x<<","<<c.y<<")"<<endl;
    }
    return 0;
}
