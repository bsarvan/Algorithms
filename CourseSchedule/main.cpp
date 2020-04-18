//
//  main.cpp
//  CourseSchedule
//
//  Created by bsarvan on 29/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

list<int>* make_graph(int num, vector<vector<int>> preq) {
    list<int> *adj = new list<int>[num];
    
    for (auto v:preq) {
        adj[v[1]].emplace_back(v[0]);
    }
    
    return adj;
}


void courseScheduleHelper(list<int> *adj, int node, vector<int> &visited, stack<int> &Stack) {
    
    visited[node] = true;
    
    for(auto it:adj[node]) {
        if (visited[it] == false) {
            courseScheduleHelper(adj, it, visited, Stack);
        }
    }
    
    Stack.push(node);
}

void courseSchedule(list<int> *adj, int numCourses) {
    stack<int> Stack;
    vector<int> visited(numCourses, false);
    
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == false) {
            courseScheduleHelper(adj, i, visited, Stack);
        }
    }
    
    for (int i=0;i<numCourses;i++) {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    //vector<vector<int>> preq = {{1,0},{2,0},{3,1},{3,2}};
    vector<vector<int>> preq = {{1, 0}, {2, 1}, {3, 2}};
    int numCourses = 4;
    list<int> *adj;
    
    adj = make_graph(numCourses, preq);
    
    for (int i = 0; i < numCourses; i++) {
        cout<<i<<" : ";
        list<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    
    courseSchedule(adj, numCourses);

    return 0;
}
