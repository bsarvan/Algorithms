//
//  main.cpp
//  KClosestPointInPlane
//
//  Created by Bharat Sarvan on 06/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 
 We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

 (Here, the distance between two points on a plane is the Euclidean distance.)

 You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

  

 Example 1:

 Input: points = [[1,3],[-2,2]], K = 1
 Output: [[-2,2]]
 Explanation:
 The distance between (1, 3) and the origin is sqrt(10).
 The distance between (-2, 2) and the origin is sqrt(8).
 Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
 Example 2:

 Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 Output: [[3,3],[-2,4]]
 (The answer [[-2,4],[3,3]] would also be accepted.)
  

 Note:

 1 <= K <= points.length <= 10000
 -10000 < points[i][0] < 10000
 -10000 < points[i][1] < 10000
 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        
        for (auto p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            
            vector<int> point;
            point.emplace_back(p[0]);
            point.emplace_back(p[1]);
            
            pq.push(make_pair(dist, point));
        }
        
        vector<vector<int>> result;
        
        while(K--) {
            result.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input = {{1,3}, {-2,2}};
    
    Solution sol;
    
    vector<vector<int>> points = sol.kClosest(input, 1);
    
    for(auto point : points) {
        for(auto p : point) {
            cout<<p<<" ";
        }
        cout<<endl;
    }
    return 0;
}
