//
//  main.cpp
//  MaxWeightedPath
//
//  Created by Bharat Sarvan on 16/11/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 You are given an array of arrays of integers, where each array corresponds to a row in a triangle of numbers.
 For example, [[1], [2, 3], [1, 5, 1]] represents the triangle:

   1
  2 3
 1 5 1
 We define a path in the triangle to start at the top and go down one row at a time to an adjacent value, eventually ending with an entry on the bottom row.
 For example, 1 -> 3 -> 5. The weight of the path is the sum of the entries.

 Write a program that returns the weight of the maximum weight path.
 
 */

#include <iostream>
#include <vector>
using namespace std;

int find_max(vector<int> A){
    int largest = INT_MIN;
    for (auto a:A) {
        if (a > largest) {
            largest = a;
        }
    }
    return largest;
}
int main(int argc, const char * argv[]) {
    cout<<"Algorithm to find the maximum weighted path"<<endl;
    
    vector<vector<int>> input = {{1}, {2,3}, {1,5,1}};
    
    int weight = 0;
    for (int level = 0; level < input.size(); level++) {
        weight += find_max(input[level]);
    }
    
    cout<<"The maximum weight is "<<weight<<endl;
    
    return 0;
}

//Time Complexity is O(level * max(Length at each level))
