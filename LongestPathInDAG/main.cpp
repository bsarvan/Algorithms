//
//  main.cpp
//  LongestPathInDAG
//
//  Created by Bharat Sarvan on 15/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int V = 5;
list<int> *adj;
vector<int> dp(V);

void addEdge(int u, int v) {
    adj[u].emplace_back(v);
}


void dfs (int u, vector<int> &visited) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            
            dfs(v, visited);
        }
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

int longestPath() {
    vector<int> visited(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }
    
    int maxPath = 0;
    for (auto v : dp) {
        maxPath = max(maxPath, v);
    }
    
    return maxPath;
}

void printGraph() {
    
    for (int i = 0; i < V; i++) {
        cout<<i<<" - ";
        for (auto v : adj[i]) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    
    adj = new list<int>[5];
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 4);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    
    int result = longestPath();
    cout<<"Longest Path - "<<result<<endl;
    
    return 0;
}
