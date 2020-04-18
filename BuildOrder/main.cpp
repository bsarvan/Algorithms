//
//  main.cpp
//  BuildOrder
//
//  Created by bsarvan on 16/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    
public:
    Graph(int n) {
        V = n;
        adj = new list<int>[n];
    }
    
    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
    }
    
    void printGraph() {
        
        for (int i=0;i<V;i++) {
            cout<<i<<" : ";
            for (auto it:adj[i]) {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    int numVertices() {
        return V;
    }
    
    bool hasIncomingEdges(int u) {
        for (int i=0;i<V;i++) {
            for (auto it:adj[i]) {
                if (it == u){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Graph graph(5);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    
    graph.printGraph();
    
    cout<<(graph.hasIncomingEdges(3)?"True":"False")<<endl;
    
    return 0;
}
