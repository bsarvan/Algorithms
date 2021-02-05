//
//  main.cpp
//  MaximumSizeSet
//
//  Created by Bharat Sarvan on 15/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//
/*
 You are given a DAG N with N nodes and M edges. You are building a graph G^. G^ contains the same vertex set as G and all edges are available in G. Moreover,

 If there exists an edge between vertex u and v in G, then there does not exist an edge between vertex v and u in G^.
 If there exists an edge between vertex u and v in G and also between v and w in G, then there exists an edge between vertex u and w in G^.
 For G^, find the maximum possible size of S where S is a set of vertices in G^ such that there exists an edge between every unordered pair of vertex present in S.

 The meaning of unordered is that there must exist an edge between every pair of vertex (u,v), that is, either u - > v or v - > u must be in an edge set.

 Input format

 The first line contain two integer N and M describing nodes and edges in graph G.
 Next M lines contain two integers u and v representing an edge from u to v.
 Output format
 Print the maximum possible size of set S.

 Constraints

 SAMPLE INPUT
 3 2
 1 2
 2 3
 SAMPLE OUTPUT
 3
 Explanation
 G^ has following edges.

 1 -> 2
 2 -> 3
 1 -> 3

 Take S ={1,2,3}. It is a  valid choice as every pair of vertex has an edge between them.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> *graph;

void dfs(int i, vector<int> &visited) {
    visited[i] = true;
    for (auto node : graph[i]) {
        if (visited[node] == false) {
            dfs(node, visited);
        }
    }
}

int main() {
    int m, n;
    vector<int> visited;
    cin>>m>>n;
    
    graph = new vector<int>[m];
    
    int tmp = n;
    while(n--) {
        int u, v;
        cin>>u>>v;
        graph[u].emplace_back(v);
    }

    n = tmp;

    visited.resize(m + 1, false);
    for (int i = 1; i <= m; i++) {
        if (visited[i] == false) {
            dfs(i, visited);
        }
    }

    int count = 0;
    for (int i = 0; i <= m; i++) {
        if (visited[i]) count++;
    }

    cout<<count<<endl;
}
