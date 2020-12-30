//
//  main.cpp
//  DetectLoopDirectedGraph
//
//  Created by bsarvan on 29/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

/* Detecting a loop in a directed graph */
#define NUM_V   4
bool helper(list<int> *graph, int u, bool* visited, bool* recStack)
{
    visited[u]=true;
    recStack[u]=true;
   
    for (auto n:graph[u])
    {
        if(recStack[n]) //if vertice v is found in recursion stack of this DFS traversal
            return true;
        else if(n==u) //if there's an edge from the vertex to itself
            return true;
        else if(!visited[n])
        {   if(helper(graph, n, visited, recStack))
                return true;
        }
    }
    recStack[u]=false;
    return false;
}
/*
 /The wrapper function calls helper function on each vertices which have not been visited.
 Helper function returns true if it detects a back edge in the subgraph(tree) or false.
 */
bool isCyclic(list<int> *graph, int V)
{
    bool visited[V];  //array to track vertices already visited
    bool recStack[V]; //array to track vertices in recursion stack of the traversal.
    for(int i = 0;i<V;i++) {
        visited[i]=false;
        recStack[i]=false;  //initialize all vertices as not visited and not recursed
    }
    
    for(int u=0;u<V;u++) //Iteratively checks if every vertices have been visited
    {
        if(visited[u]==false)
        {  if(helper(graph, u, visited, recStack)) //checks if the DFS tree from the vertex contains a cycle
                return true;
        }
    }
    return false;
}
/*
 Driver function
 */
int main()
{
    list<int>* graph = new list<int>[NUM_V];
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    bool res = isCyclic(graph, NUM_V);
    cout<<res<<endl;
}
