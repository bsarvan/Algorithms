//
//  main.cpp
//  ShortestPath
//
//  Created by bsarvan on 28/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <float.h>
using namespace std;

ifstream infile("/Users/bharat.sarvan/Me/workspace/Programming/ShortestPath/input.txt");


class DirectedEdge
{
    int v;
    int w;
    double weight;
    
public:
    DirectedEdge(){};
    DirectedEdge(int v, int w, double weight):v(v),w(w),weight(weight) {}
    
    double getWeight()
    {  return weight;  }
    
    int from()
    {  return v;  }
    
    int to()
    {  return w;  }
    
    void PrintString()
    {
        cout<<"["<<v<<"|"<<w<<"|"<<weight<<"]";
    }
};

class EdgeWeightedDigraph {
    int V; //Number of Vertices
    int E; // Number of Edges
    
    list<DirectedEdge> *adj;
    
public:
    EdgeWeightedDigraph(int V):V(V), adj(new list<DirectedEdge>[V]){}
    int getV() {  return V;  }
    int getE() {  return E;  }
    list<DirectedEdge> getAdj(int v) { return adj[v];}
    
    void addEdge(DirectedEdge e)
    {
        adj[e.from()].push_front(e);
        E++;
    }
    
    void printEdgeList() {
        list<DirectedEdge>::iterator dEdge_iter;
        
        for(int i=0;i<V;i++) {
            cout<<"Vertex - "<<i;
            for(dEdge_iter = adj[i].begin();dEdge_iter != adj[i].end();dEdge_iter++) {
                cout<<" -> ";
                dEdge_iter->PrintString();
            }
            cout<<endl;
        }
    }
};

    
class DijkstrasSP {
    vector<DirectedEdge> edgeTo;
    vector<double> distTo;
    priority_queue<pair<double, int>, vector<pair<double,int>>, greater<>> pq;
    
    
public:
    DijkstrasSP(EdgeWeightedDigraph G, int s) {
//        edgeTo = new DirectedEdge[G.getV()];
//        distTo = new double[G.getV()];
        edgeTo.resize(G.getV());
        distTo.resize(G.getV(), DBL_MAX);
        
        distTo[s]=0.0;
        pq.emplace(s,0.0);
        while(!pq.empty()) {
            pair<double,int> p = pq.top();
            pq.pop();
            // Relax the edges originating from the vertex p.second
            relax(G,p.second);
            
        }
    }
    
    void relax(EdgeWeightedDigraph G, int v) {
        // Get all the adjacent edges for the vertex v and relax.
        for(auto e:G.getAdj(v)) {
            int w = e.to();
            if (distTo[w] > distTo[v] + e.getWeight()) {
                distTo[w] = distTo[v] + e.getWeight();
                edgeTo[w] = e;
                pq.push(make_pair(distTo[w], w));
            }
        }
        return;
    }
    
    
    bool hasPathTo(int w) {
        return (distTo[w] != INT_MAX);
    }
    
    void printDistTo(EdgeWeightedDigraph G) {
        for (int i = 0; i < G.getV(); i++) {
            cout<<i<<" - "<<distTo[i]<<endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    cout<<"Algorithm to find the shortest path"<<endl;
    int vertices, edges;
    infile >> vertices >> edges;
    int v,w;
    double weight;
    
    EdgeWeightedDigraph graph(10);

    while (infile >> v >> w >> weight) {
        graph.addEdge(DirectedEdge(v,w,weight));
    }

    graph.printEdgeList();

    DijkstrasSP *SP = new DijkstrasSP(graph, 0);
    
    cout<<"Distance of the vertices form the source vertex 0 is as below - "<<endl;
    SP->printDistTo(graph);
    
    
    return 0;
}
