//
//  main.cpp
//  DependancyGraph
//
//  Created by Bharat Sarvan on 15/10/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Graph {
    int V;
    list<char> *adj;
public:
    Graph(int V, unordered_map<char, vector<char>> input) {
        this->V = V;
        adj = new list<char>[V];
        
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
