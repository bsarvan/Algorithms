//
//  main.cpp
//  LongestPathEdgeWeight
//
//  Created by Bharat Sarvan on 25/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given a tree where each edge has a weight, compute the length of the longest path in the tree.

 For example, given the following tree:

    a
   /|\
  b c d
     / \
    e   f
   / \
  g   h
 and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f, with a length of 17.

 The path does not have to pass through the root, and each node can have any amount of children.
 
 
 */
#include <iostream>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->weight = w;
    }
};


class Graph {
    
}


int computeLongestWeightedPath(

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
