//
//  main.cpp
//  CourseScheduleII
//
//  Created by bsarvan on 05/03/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 
 Example 1 -
 Input: numCourses = 2, prerequisites = [[1,0]]
 Output: true
 Explanation: There are a total of 2 courses to take.
              To take course 1 you should have finished course 0. So it is possible.
 
 
 Example 2 -
 Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 Output: false
 Explanation: There are a total of 2 courses to take.
              To take course 1 you should have finished course 0, and to take course 0 you should
              also have finished course 1. So it is impossible.
 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> g(numCourses);
        vector<int> in(numCourses);
        
        for(auto x: prerequisites) {
            g[x[1]].insert(x[0]);
            in[x[0]]++;
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
            for(int i : g[x]) {
                in[i]--;
                if(in[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        return (vis == numCourses);
    }
};

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find if the courses can be finished given the dependancies"
    
    // Course-0 is needed to completed before taking Course-1
    vector<vector<int>> preq = {{1,0}};
    Solution obj;
    
    int result = obj.canFinish(2, preq);
    
    cout<<result<<endl;
    
    return 0;
}
