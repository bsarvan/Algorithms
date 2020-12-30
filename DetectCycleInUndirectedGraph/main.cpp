//
//  main.cpp
//  DetectCycleInUndirectedGraph
//
//  Created by Bharat Sarvan on 04/07/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

// C++ program to detect cycle in an undirected graph
// using BFS.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicConntected(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {

        // Dequeue a vertex from queue and print it
        int u = q.front();
        cout<<"Processing vertex - "<<u<<endl;
        q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex u. If a adjacent has not been visited,
        // then mark it visited and enqueue it. We also
        // mark parent so that parent is not considered
        // for cycle.
        for (auto v : adj[u]) {
            cout<<"Analysing adjacent vertex - "<<v<<endl;
            if (!visited[v]) {
                
                visited[v] = true;
                q.push(v);
                parent[v] = u;
                
            } else if (parent[u] != v) {
                
                cout<<"Cycle Detected - "<<u<<" "<<v<<" "<<parent[u]<<endl;
                return true;
            }
        }
    }
    return false;
}

bool isCyclicDisconntected(vector<int> adj[], int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i,
                                        V, visited))
            return true;
    return false;
}

// Driver program to test methods of graph class
int main()
{
    int V = 3;
    vector<int> adj[V];
//    addEdge(adj, 0, 1);
//    addEdge(adj, 1, 2);
//    addEdge(adj, 2, 3);
//    addEdge(adj, 2, 4);
//    addEdge(adj, 3, 4);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    
    if (isCyclicDisconntected(adj, V))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;

    return 0;
}
