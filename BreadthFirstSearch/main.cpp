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
    
    // prints BFS traversal from a given source s
    void BFS(int s);
    void DFS_recursive(int s);
    void DFS_iterative(int s);
    void DFS(int s);
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
    
    for (int i=0;i<visited.size();i++)
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
    
    cout << "Following is Breadth Traversal "
    << "(starting from vertex 2) \n";
    g.BFS(0);
    //g.DFS(0);
    //g.DFS_Iterative(0);
    
    cout<<endl;
    
    return 0;
}
