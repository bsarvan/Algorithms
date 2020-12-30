//
//  main.cpp
//  CourseSchedule
//
//  Created by bsarvan on 29/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

  

 Example 1:

 Input: numCourses = 2, prerequisites = [[1,0]]
 Output: true
 Explanation: There are a total of 2 courses to take.
              To take course 1 you should have finished course 0. So it is possible.
 Example 2:

 Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 Output: false
 Explanation: There are a total of 2 courses to take.
              To take course 1 you should have finished course 0, and to take course 0 you should
              also have finished course 1. So it is impossible.
 
 */

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <queue>
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
    cout<<"Pushing node - "<<node<<endl;
    Stack.push(node);
}


// Course Schedule using DFS
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



// Course Shedule using DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> g(numCourses);
        vector<int> in(numCourses);
        stack<int> S;
        
        for(auto x: prerequisites) {
            g[x[0]].insert(x[1]);
            in[x[1]]++;
        }
        
        queue<int> q;
        for(int i = 0;i<numCourses;i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        
        int vis = 0;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            vis++;
            S.push(x);
            for(int i : g[x]) {
                in[i]--;
                if(in[i] == 0) {
                    q.push(i);
                }
            }
          
        }
        
        while(!S.empty()) {
            cout<<S.top()<<endl;
            S.pop();
        }
        
        return (vis == numCourses);
    }
};



int main(int argc, const char * argv[]) {
    //vector<vector<int>> preq = {{1,0},{2,0},{3,1},{3,2}};
    vector<vector<int>> preq = {{1, 0}, {2, 1}, {3, 2},{4,2}};
    int numCourses = 5;
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
    Solution sol;
    
    sol.canFinish(numCourses, preq);
    return 0;
}
