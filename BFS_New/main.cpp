//
//  main.cpp
//  BreadthFirstSearch
//
//  Created by bsarvan on 18/07/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include<iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
    bool *visited;
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor
    
    // function to add an edge to graph
    void addEdge(int v, int w);
    int numOfVertices() {
        return V;
    }
    
    // prints BFS traversal from a given source s
    void BFS(int s);
    void DFS_recursive(int s);
    void DFS_Iterative(int s);
    void DFS(int s);
    list<int> getAdj(int v) {
        return adj[v];
    }
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;
    
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


void Graph::DFS(int s) {
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator i;
    for(i = adj[s].begin();i != adj[s].end();i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}


void Graph::DFS_recursive(int s) {
    visited = new bool[V];
    
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    cout<<endl;
    DFS(s);
    cout<<endl;
    
    
    
}


void Graph::DFS_Iterative(int s) {
    stack<int> S;
    visited = new bool[V];
    
    for (int i=0;i<V;i++)
        visited[i] = false;
    
    visited[s] = true;
    S.push(s);
    
    while(!S.empty()) {
        int tmp = S.top();
        S.pop();
        cout<<tmp<<" ";
        list<int>::iterator i;
        for(i = adj[tmp].begin();i != adj[tmp].end();i++) {
            if (!visited[*i]) {
                S.push(*i);
                visited[*i] = true;
            }
        }
        
    }
}

class Paths  {
    Graph G;
    int source;
public:
    Paths(Graph G, int S):G(G), source(S) {}
    bool hasPathTo(int v);
    vector<int> pathTo(int v);
};

bool Paths::hasPathTo(int v) {
    for (auto n:G.getAdj(source)) {
        if (n == v) {
            cout<<source<<" and "<<v<<" are connected"<<endl;
            return true;
        }
    }
    cout<<"There is no path connecting to "<<source<<" and "<<v<<endl;
    return false;
}



class Search {
    Graph G;
    int source;
public:
    Search(Graph G,int s):G(G),source(s) {}
    void marked(int v);
    int count(int v);
};

void Search::marked(int d) {
    for (int i = 0; i < G.numOfVertices();i++) {
        for (auto v : G.getAdj(i)){
            if (v == d) {
                cout<<i<<" and "<<v<<" are connected"<<endl;
            }
        }
    }
    return;
}
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is Breadth First Traversal "
    << "(starting from vertex 2) \n";
    //g.BFS(0);
    //g.DFS(0);
    //g.DFS_Iterative(0);
    
    Paths path(g,1);
    path.hasPathTo(2);
    
    //Search search(g,2);
    //search.marked(3);
    
    cout<<endl;
    
    return 0;
}
