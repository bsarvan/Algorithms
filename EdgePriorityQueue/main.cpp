//
//  main.cpp
//  EdgePriorityQueue
//
//  Created by bsarvan on 25/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


class Edge {
    int u;
    int v;
    int wt;
public:
    Edge(int a, int b, int w):u(a), v(b), wt(w) {};
    
    bool operator==(const Edge &E) {
        return (wt == E.wt);
    }
    
    bool operator>(const Edge E) const {
        return (wt > E.wt);
    }
    
    void printEdge() {
        cout<<u<<"-->"<<v<<":"<<wt<<endl;
    }
};

int main() {
    
    vector<Edge> edges;
    
    edges.emplace_back(Edge(1,2,10));
    edges.emplace_back(Edge(1,3,5));
    edges.emplace_back(Edge(1,4,7));
    edges.emplace_back(Edge(1,5,20));
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    cout<<"List of Edges - "<<endl;
    for (auto e:edges) {
        e.printEdge();
    }
    
    for (int i = 0; i < 4; i++) {
        pq.push(edges[i]);
    }
    
    cout<<"List of Edges in PQ - "<<endl;
    while(!pq.empty()) {
        Edge E = pq.top();
        E.printEdge();
        pq.pop();
    }

    return 0;
}
