//
//  main.cpp
//  DijkstrasAlgorithm
//
//  Created by Bharat Sarvan on 30/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define V 9

int minDistance(const vector<int> &distTo, const vector<bool> &sptSet) {
    int min = INT_MAX; int min_index = 0;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false and distTo[v] <= min) {
            min = distTo[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstras(vector<vector<int>> graph, int source) {
    vector<int> distTo(V, INT_MAX);
    vector<bool> sptSet(V, false);
    
    distTo[source] = 0;
    
    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(distTo, sptSet);
        sptSet[u] = true;
        
        for(int v = 0; v < V; v++) {
            if (!sptSet[v] and graph[u][v] != 0 and distTo[u] != INT_MAX and distTo[u] + graph[u][v] < distTo[v]) {
                distTo[v] = distTo[u] + graph[u][v];
            }
        }
    }
    
    for (int i = 0; i<V; i++) {
        cout<<i<<" - "<<distTo[i]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}
                                };
    
    dijkstras(graph, 0);
}
