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


// Prims Algorithm on Graph as Adjacency Matrix

vector<vector<int>> G = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};



void PrimsAlgorithm(vector<vector<int>> G) {
    
    int V = 5;
    vector<bool> selected(G.size(), false);
    int no_edges = 0;
    
    while(no_edges < V - 1) {
        
        int x = 0, y = 0, min_weight = INT_MAX;
        for (int i = 0; i < G.size(); i++) {
            // Look for the edges only if the source vertex is included in MST
            if (selected[i]) {
                for (int j = 0; j < G[0].size(); j++) {
                    // Evaluate the vertex which is not yet included in MST
                    if (!selected[j] and G[i][j]) {
                        if (min_weight > G[i][j]) {
                            min_weight = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edges++;
    }
    
    
    for (int i = 0; i < selected.size(); i++) {
        if (selected[i]) {
            cout<<i<<" ";
        }
    }
    
    cout<<endl;
    return;
    
}
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
    
    cout<<endl;
    cout<<"=============================================="<<endl;
    
    cout<<"Prims Algorith on Adjacency Matrix"<<endl;
    
    PrimsAlgorithm(G);
    
    return 0;
}
