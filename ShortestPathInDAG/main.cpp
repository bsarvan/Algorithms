//
//  main.cpp
//  ShortestPathInDAG
//
//  Created by Bharat Sarvan on 31/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;


struct Edge {
    int u, v, weight;
    Edge(int U, int V, int W):u(U), v(V), weight(W) {}
};


class Graph {
    int V;
public:
    vector<vector<Edge>> adj;
    Graph(vector<Edge> edges, int N) {
        V = N;
        adj.resize(N);
        
        for (auto edge : edges) {
            adj[edge.u].emplace_back(edge);
        }
    }
    
};


void DFS(Graph &graph, int u, vector<bool> &visited, vector<int> &departure, int &time ) {
    visited[u] = true;
    for (auto edge : graph.adj[u]) {
        int v = edge.v;
        if (!visited[v]) {
            DFS(graph, v, visited, departure, time);
        }
    }
    
    departure[time] = u;
    time++;
}


void findShortestDistance (Graph &graph, int source, int N) {
    vector<int> departure(N, -1);
    vector<bool> visited(N, false);
    int time = 0;
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, departure, time);
        }
    }
    
    vector<int> cost(N, INT_MAX);
    cost[source] = 0;
    for (int i = N - 1 ; i >= 0; i--) {
        int u = departure[i];
        for (auto edge : graph.adj[u]) {
            int v = edge.v;
            if (cost[u] != INT_MAX and cost[v] > cost[u] + edge.weight) {
                cost[v] = cost[u] + edge.weight;
            }
        }
    }
    
    // print shortest paths
    for (int i = 0; i < N - 1; i++) {
        cout << "dist(" << source << ", " << i << ") = " << setw(2) << cost[i];
        cout << endl;
    }
}




int main(int argc, const char * argv[]) {
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
        {5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
    };
 
    // Number of nodes in the graph
    int N = 8;

    // create a graph from edges
    Graph graph(edges, N);
 
    // source vertex
    int source = 7;
 
    // find Shortest distance of all vertices from given source
    findShortestDistance(graph, source, N);
 
    return 0;
}
