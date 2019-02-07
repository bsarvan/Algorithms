//
//  main.cpp
//  Graph
//
//  Created by bsarvan on 05/06/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;


void addEdge(unordered_map<int,unordered_set<int>>& graph, int u, int v) {
    graph[u].emplace(v);
    graph[v].emplace(u);
}

void printGraph(unordered_map<int, unordered_set<int>> graph) {
    unordered_map<int, unordered_set<int>>::iterator iter;
    for(iter = graph.begin();iter != graph.end();iter++){
        cout<<"\nAdjacency List of vertex "<<iter->first<<"\nhead ";
        unordered_set<int>::iterator it;
        for(it=iter->second.begin();it!=iter->second.end();it++) {
            cout<<" -> "<<*it;
        }
        cout<<endl;
    }
    return;
}

int main(int argc, const     char * argv[]) {
    cout<<"Test program to implement a graph"<<endl;
    
    unordered_map<int,unordered_set<int>> graph;
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);
    return 0;
}
