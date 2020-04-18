//
//  main.cpp
//  EdgeWeightedGraphAPI
//
//  Created by bsarvan on 20/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
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
    Edge(int a, int b, int c):v(a),w(b),weight(c) {}
    
    double getWeight() {
        return weight;
    }
    
    int either() {
        return v;
    }
    
    int other(int vertex) {
        if (v == vertex) {
            return w;
        } else {
            return v;
        }
    }
    
    int compareTo(Edge that) {
        if (weight < that.weight)
            return -1;
        else if (weight > that.weight)
            return 1;
        else return 0;
    }
    
    void toString() {
        cout<<v<<" --- "<<w<<" : "<<weight<<endl;
    }
};


class EdgeWeightedGraph {
    int V;
    int E;
    vector<list<Edge>> adj;
    
public:
    EdgeWeightedGraph(int vertexes) {
        V = vertexes;
        adj.resize(V);
    }
    
    void addEdge(Edge e) {
        int v = e.either();
        int w = e.other(v);
        
        adj[v].emplace_back(e);
        adj[w].emplace_back(e);
    }
    
    list<Edge> edgesForV(int v) {
        return adj[v];
    }
    
    int getVertexes(){
        return V;
    }
    
    vector<Edge> getEdges() {
        vector<Edge> edges;
        
        for(int i=0;i<V;i++) {
            for (auto e:adj[i]){
                if (e.other(i) > i) {
                    edges.emplace_back(e);
                }
            }
        }
        return edges;
    }
    
};

class UF {
    vector<int> id;
    int count;
public:
    UF(int N):count(N) {
        id.resize(N);
        
        for (int i=0;i<N;i++){
            id[i] = i;
        }
    }
    
    int getCount() {
        return count;
    }
    
    int find(int p) {
        return id[p];
    }
    
    void Union(int p, int q) {
        int pID = find(p);
        int qID = find(q);
        
        if (pID == qID) return;
        
        for (int i = 0; i<id.size();i++) {
            if (id[i] == pID) {
                id[i] = qID;
            }
            
        }
        count--;
    }
    
    bool connected(int p, int q) {
        return id[p] == id[q];
    }
    
    
};


class KruskalsMST {
    
    vector<Edge> mst;
    
public:
    KruskalsMST(EdgeWeightedGraph G) {
        priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
        vector<Edge> edges = G.getEdges();
        for (auto e:edges) {
            pq.push(e);
        }
        UF uf(G.getVertexes());
        
        while(!pq.empty() && mst.size() < G.getVertexes() - 1) {
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int w = e.other(v);
            
            if (uf.connected(v,w)) continue;
            uf.Union(v, w);
            mst.emplace_back(e);
        }
    }
    
};

int main(int argc, const char * argv[]) {
    cout<<"EdgeWeightGraph API"<<endl;
    EdgeWeightedGraph *G = new EdgeWeightedGraph(8);
    
    G->addEdge(Edge(4,5,0.35));
    G->addEdge(Edge(4,7,0.37));
    G->addEdge(Edge(5,7,0.28));
    G->addEdge(Edge(0,7,0.16));
    G->addEdge(Edge(1,5,0.32));
    G->addEdge(Edge(0,4,0.38));
    G->addEdge(Edge(2,3,0.17));
    G->addEdge(Edge(1,7,0.19));
    G->addEdge(Edge(0,2,0.26));
    G->addEdge(Edge(1,2,0.36));
    G->addEdge(Edge(2,7,0.34));
    G->addEdge(Edge(6,2,0.40));
    G->addEdge(Edge(3,6,0.52));
    G->addEdge(Edge(6,0,0.58));
    G->addEdge(Edge(6,4,0.93));
    
    list<Edge> edges = G->edgesForV(1);
    
    for (auto e:edges) {
        e.toString();
    }
    
    
    
    
    while
    return 0;
}
