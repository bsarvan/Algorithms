//
//  main.cpp
//  MeetingRooms
//
//  Created by bsarvan on 21/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &A);
              
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<int> T;
        
        if (intervals.size() == 1) {
            return 1;
        }
        
        sort(intervals.begin(), intervals.end());
        
        for (auto it:intervals) {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        
    
        int startTime = intervals[0][0];
        int endTime = intervals[0][1];
        
        int rooms = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if (endTime > intervals[i][0]) {
                rooms++;
                startTime = intervals[i][0];
                endTime = intervals[i][1];
            }
        }
        return rooms;
    }
};


int Solution::solve(vector<vector<int> > &A) {
    vector<int> startTimes;
    vector<int> endTimes;
    
    for (int i = 0; i < A.size(); i++) {
        startTimes.emplace_back(A[i][0]);
        endTimes.emplace_back(A[i][1]);
    }
    
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());
    
    // The two pointers in the algorithm: e_ptr and s_ptr.
    int startPointer = 0, endPointer = 0;

    // Variables to keep track of maximum number of rooms used.
    int usedRooms = 0;

    // Iterate over intervals.
    while (startPointer < A.size()) {

      // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
      if (startTimes[startPointer] >= endTimes[endPointer]) {
        usedRooms -= 1;
        endPointer += 1;
      }

      // We do this irrespective of whether a room frees up or not.
      // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
      // remain the same in that case. If no room was free, then this would increase used_rooms
      usedRooms += 1;
      startPointer += 1;

    }
    return (usedRooms);
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{0,30}, {5,10},{15,20}};
    // 0 5 15
    // 10 20 30
    //vector<vector<int>> intervals = {{7,10},{2,4}};
    
    Solution obj;
    
    int result = obj.solve(intervals);
    
    cout<<"Number of meetings room required "<<result<<endl;
    return 0;
}
