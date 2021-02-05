//
//  main.cpp
//  CountAllPaths
//
//  Created by Bharat Sarvan on 05/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;


class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int v) {
        this->V = v;
        adj = new list<int>[V];
    }
    
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }
    
    list<int> getAdjacencies(int u) {
        return adj[u];
    }
};

// DFS Algorithm to Print All Paths
void CountAllPaths(Graph g, int src, int dest, int &count) {
    if (src == dest) {
        count++;
        return;
    }
    
    // Skipping the tracking of visited node, since we want to get the total count of all paths
    // to destination from the given source
    for (auto node : g.getAdjacencies(src)) {
        CountAllPaths(g, node, dest, count);
    }
    return;
}


int main(int argc, const char * argv[]) {

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int s = 0, d = 3;
    
    int count = 0;
    CountAllPaths(g, s, d, count);
    
    cout<<count<<endl;
    return 0;
}
