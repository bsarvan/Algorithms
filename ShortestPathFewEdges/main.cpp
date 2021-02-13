//
//  main.cpp
//  ShortestPathFewEdges
//
//  Created by Bharat Sarvan on 31/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct GraphVertex {
    struct DistanceWithFewerEdges {
        int distance , min_num_edges;
    };
    
    DistanceWithFewerEdges distance_with_fewer_edges = DistanceWithFewerEdges{INT_MAX, 0};
    
    struct VertexWithDistance {
        GraphVertex &vertex;
        int distance;
    };
    
    vector<VertexWithDistance> edges;
    int id;
    const GraphVertex* pred = nullptr;
};


struct Comp {
    bool operator() (const GraphVertex* lhs, const GraphVertex* rhs) {
        return lhs->distance_with_fewer_edges.distance < rhs->distance_with_fewer_edges.distance ||
              (lhs->distance_with_fewer_edges.distance == rhs->distance_with_fewer_edges.distance &&
               lhs->distance_with_fewer_edges.min_num_edges < rhs->distance_with_fewer_edges.min_num_edges);
        
    }
};


void DijkstrasShortestPath(GraphVertex* s, GraphVertex* t) {
    // Distance of starting point would be zero.
    // Initialize the distance of the starting point
    s->distance_with_fewer_edges = {0,0};
    set<GraphVertex*, Comp> node_set;
    
    node_set.emplace(s);
    
    while(!node_set.empty()) {
        GraphVertex* u = *node_set.cbegin();
        
        if (u->id == t->id) {
            break;
        }
        
        node_set.erase(node_set.cbegin());
        
        for(const GraphVertex::VertexWithDistance &v : u->edges) {
            int v_distance = v.vertex.distance_with_fewer_edges.distance + v.distance;
            int v_num_edges = v.vertex.distance_with_fewer_edges.min_num_edges + 1;
            
            if (v.vertex.distance_with_fewer_edges.distance > v_distance ||
                (v.vertex.distance_with_fewer_edges.distance == v_distance &&
                 v.vertex.distance_with_fewer_edges.min_num_edges > v_num_edges)) {
                node_set.erase(&v.vertex);
                v.vertex.pred = u;
                v.vertex.distance_with_fewer_edges = {v_distance, v_num_edges};
                node_set.emplace(&v.vertex);
            }
        }
    }
}



int NodeWithMinDistance(const vector<int> &distTo, const vector<bool> &ShortestPathSet) {
    int min = INT_MAX;
    int min_node = 0;
    
    for (int i = 0; i < distTo.size(); i++) {
        if (ShortestPathSet[i] == false and distTo[i] < min) {
            min = distTo[i];
            min_node = i;
        }
    }
    return min == INT_MAX ? INT_MAX : min_node;
}


void PrintPath(vector<int> parent, int d) {
    if (parent[d] == -1) {
        cout<<d;
        return;
    } else {
        PrintPath(parent, parent[d]);
        cout<<"->"<<d;
    }
}

void PrintAllPaths(vector<int> parent) {
    for (int i = 0; i < parent.size(); i++) {
        cout<<"Path to "<<i<<" - ";
        PrintPath(parent, i);
        cout<<endl;
    }
    
}


void ShortestPathWithLeastEdges(vector<vector<int>> grid, int S, int E) {
    vector<int> distTo(grid.size(), INT_MAX);
    vector<bool> ShortestPathSet(grid.size(), false);
    vector<int> PathLength(grid.size(), 0);
    vector<int> parent(grid.size(), -1);
    
    distTo[0] = 0;
    for (int i = 0; i < grid.size(); i++) {
        int u = NodeWithMinDistance(distTo, ShortestPathSet);
        
        if (u == INT_MAX) {
            break;
        } else {
            ShortestPathSet[u] = true;
            for (int v = 0; v < grid[0].size(); v++) {
                if (grid[u][v] != INT_MAX and ShortestPathSet[v] == false and distTo[v] > distTo[u] + grid[u][v]) {
                    distTo[v] = distTo[u] + grid[u][v];
                    parent[v] = u;
                    PathLength[v] = PathLength[u] + 1;
                } else if (grid[u][v] != INT_MAX and ShortestPathSet[v] == false and distTo[v] == distTo[u] + grid[u][v] and PathLength[v] > PathLength[u] + 1) {
                    parent[v] = u;
                    PathLength[v] = PathLength[u] + 1;
                }
            }
        }
    }
    
    if (distTo[E] == INT_MAX) {
        cout<<"There is no Path from Source - "<<S<<", to End - "<<E<<endl;
    } else {
        PrintPath(parent, E);
        cout<<endl<<endl;
    }
    
    cout<<"All Shortest Paths to the vertices are -"<<endl;
    PrintAllPaths(parent);
}





int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the shortest path with minimum edges"<<endl;
    vector<vector<int>> grid = { { 0, 1, INT_MAX, INT_MAX, 10 },
                                 { 1, 0, 4, INT_MAX, INT_MAX },
                                 { INT_MAX, 4, 0, 7, INT_MAX },
                                 { INT_MAX, INT_MAX, 7, 0, 2 },
                                 { 10, INT_MAX, INT_MAX, 2, 0 } };
    
    ShortestPathWithLeastEdges(grid, 0, 3);
    return 0;
}
