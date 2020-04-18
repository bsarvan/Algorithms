//
//  main.cpp
//  PaintVertextUndirectedGraph
//
//  Created by bsarvan on 10/03/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int V = 4;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
    return;
}

void printGraph(vector<vector<int>> adj) {
    for (int i=0;i<adj.size();i++) {
        for(int j=0;j<adj[i].size();j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {

    vector<vector<int>> adjMat;
    
    adjMat.resize(V);
    
    for(int i=0;i<V;i++) {
        adjMat[i].resize(V);
    }
    
    cout<<"Test Program for Graph adjaceny matrix"<<endl;
    cout<<"Adding edges"<<endl;
    addEdge(adjMat, 0, 1);
    cout<<"Adding next edge "<<endl;
    addEdge(adjMat, 1, 2);
    addEdge(adjMat, 1, 3);
    addEdge(adjMat, 2, 3);
    
    cout<<"Printing the Adjacancey Matrix"<<endl;
    printGraph(adjMat);
    
    return 0;
}
