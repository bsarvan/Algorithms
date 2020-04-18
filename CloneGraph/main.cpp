//
//  main.cpp
//  CloneGraph
//
//  Created by bsarvan on 14/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;



// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *graph) {
    if (!graph) {
        return NULL;
    }

    map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    queue<UndirectedGraphNode *> q;
    q.push(graph);

    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
    map[graph] = graphCopy;

    while (!q.empty()) {
        UndirectedGraphNode *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            // no copy exists
            if (map.find(neighbor) == map.end()) {
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            } else {     // a copy already exists
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    return graphCopy;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
