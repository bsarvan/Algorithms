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
using namespace std;

ifstream infile("/Users/bsarvan/Personal/Xcode Projects/CrackingCoding/ShortestPath/input.txt");



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


template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:
  
    bool find(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};

class MyPQ {
    
    priority_queue<pair<int,int>,vector<pair<int,int>,greater<>> pq;
public:
    addPQ(int v, double w) {
        pq.push(make_pair<w,v>);
    }
    erasePQ(int v, double w) {
        pq.pop();
    }
    
    bool findPQ(int v) {
        priority_queue< pair<int,int>,vector<pair<int,int>> ,greater<> > qq = pq;
        while(!qq.empty()) {
            pair<int, int> tmp = qq.top();
            if (tmp.second == v) {
                return true;
            }
        }
    }
    
};

class DijkstrasSP {
    DirectedEdge *edgeTo;
    double *distTo;
    multiset<pair<int,double>> pq;
    
public:
    DijkstrasSP(EdgeWeightedDigraph G, int s) {
        edgeTo = new DirectedEdge[G.getV()];
        distTo = new double[G.getV()];
       
        
        for(int v=0;v<G.getV();v++) {
            distTo[v] = INT_MAX;
        }
        distTo[s]=0.0;
        pq.insert({s,0.0});
        while(!pq.empty()) {
            pair<int,double> p = *pq.begin();
            pq.erase(pq.begin());
            
            relax(G,p.second);
            
        }
    }
    
    void relax(EdgeWeightedDigraph G, int v) {
        
        for(auto e:G.getAdj(v)) {
            int w = e.to();
            if (distTo[w] > distTo[v] + e.getWeight()) {
                distTo[w] = distTo[v] + e.getWeight();
                edgeTo[w] = e;
            }
            
            pq.find({w,edgeTo[w]});
            if (pq.find({w,edgeTo[w]})) {
                pq.insert({w,distTo[w]});
            } else {
                
            }
        }
        
    }
    
    
};

int main(int argc, const char * argv[]) {
    cout<<"Sample Program for Shortest Path Algorithm"<<endl;
    int vertices, edges;
    infile >> vertices >> edges;
    int v,w;
    double weight;
    
    EdgeWeightedDigraph graph(10);

    while (infile >> v >> w >> weight) {
        graph.addEdge(DirectedEdge(v,w,weight));
    }
    
    graph.printEdgeList();

    return 0;
}
