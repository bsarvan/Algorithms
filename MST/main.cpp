//
//  main.cpp
//  MST
//
//  Created by Bharat Sarvan on 25/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Edge {
    int v;
    int w;
    double weight;
public:
    Edge(int v, int w, double weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
    
    double getWeight() {
        return weight;
    }
    
    int either() {
        return v;
    }
    
    int other(int vertex) {
        return (vertex == v? w:v);
    }
    
    bool operator==(const Edge &E) {
        return (weight == E.weight);
    }
    
    bool operator>(const Edge E) const {
        return (weight > E.weight);
    }
    
    void printEdge() {
        cout<<v<<" - "<<w<<" : "<<weight<<endl;
    }
};


class EdgeWeightedGraph {
    int V;
    int E;
    list<Edge> *adj;
public:
    EdgeWeightedGraph(int V) {
        this->V = V;
        this->adj = new list<Edge>[V];
    }
    
    void addEdge(Edge e) {
        e.printEdge();
        int from = e.either();
        int to = e.other(from);
        adj[from].emplace_back(e);
        adj[to].emplace_back(e);
        E++;
    }
    
    list<Edge> getEdgesForVertex(int v) {
        return adj[v];
    }
    
    int getV() {
        return V;
    }
    
    int getE() {
        return E;
    }
};


class LazyPrimMST {
    list<Edge> mst;
    vector<bool> marked;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
public:
    LazyPrimMST(EdgeWeightedGraph G) {
        cout<<"Building MST"<<endl;
        marked.resize(G.getV(), false);
        
        visit(G, 1);
        while(!pq.empty()) {
            Edge E = pq.top();
            pq.pop();
            cout<<"Processing Edge - ";
            E.printEdge();
            
            int v = E.either();
            int w = E.other(v);
            
            if (marked[v] && marked[w]) {
                continue;
            }
            
            mst.emplace_back(E);
            if (!marked[v]) visit(G,v);
            if (!marked[w]) visit(G,w);
        }
    }
    
    void visit(EdgeWeightedGraph G, int V) {
        marked[V] = true;
        for (auto edge:G.getEdgesForVertex(V)) {
            if (!marked[edge.other(V)]) {
                pq.emplace(edge);
            }
        }
    }
    
    list<Edge> getMST() {
        return mst;
    }
};

int main(int argc, const char * argv[]) {
    cout<<"Prims Algorithm to find the MST"<<endl;
    
    EdgeWeightedGraph graph(7);
    
    graph.addEdge(Edge(5,1,4));
    graph.addEdge(Edge(5,4,9));
    graph.addEdge(Edge(4,1,1));
    graph.addEdge(Edge(4,3,5));
    graph.addEdge(Edge(1,2,2));
    graph.addEdge(Edge(2,3,3));
    graph.addEdge(Edge(3,6,8));
    graph.addEdge(Edge(2,6,7));
    graph.addEdge(Edge(4,2,3));
    
    
    LazyPrimMST mst(graph);
    list<Edge> mstEdges = mst.getMST();
    
    for (auto edge:mstEdges) {
        int v = edge.either();
        int w = edge.other(v);
        
        cout<<v<<" - "<<w<<"; wt - "<<edge.getWeight()<<endl;
    }
    
    return 0;
}
