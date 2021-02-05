//
//  main.cpp
//  2DBoardOfCharacters
//
//  Created by Bharat Sarvan on 23/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given a 2D board of characters and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

 For example, given the following board:

 [
   ['A','B','C','E'],
   ['S','F','C','S'],
   ['A','D','E','E']
 ]
 exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// isValid function to validate index boundaries and if the next character is equal to character at index in string.
bool isValid(vector<vector<char>> board, int row, int col, int index, string S) {
    return (row >=0 && row < board.size() && col >= 0 && col < board[0].size() && S[index] != board[row][col]);
}

bool existsUtil(vector<vector<char>> board, vector<vector<bool>> &visited, int x, int y, int index, string S) {
    
    if (index == S.size() - 1) {
        return true;
    }
    
    visited[x][y] = true;
    
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for (auto dir:dirs) {
        int row = x + dir[0];
        int col = y + dir[1];
        
        
        if (isValid(board, row, col, index, S) && !visited[row][col]) {
            
            if (existsUtil(board, visited, row, col, index + 1, S)) {
                return true;
            }
        }
    }
    
//    visited[x][y] = false;
    return false;
}

bool exists(vector<vector<char>> board, string S) {
    
    // Since the sequence can be begin from any where in the grid, we got to
    // check all the elements in the grid.
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            if (existsUtil(board, visited, i, j, 0, S)) {
                return true;
            }
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}
                                 };
    
    
    bool result = exists(board, "CED");
    cout<<"Result - "<<result<<endl;
    
    return 0;
}
