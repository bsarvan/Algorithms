//
//  main.cpp
//  MergeIntervals
//
//  Created by bsarvan on 13/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
};


bool compare (const Interval &a, const Interval &b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compare);
        
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= res.back().end)
                res.back().end = max(res.back().end, intervals[i].end);
            else
                res.push_back(intervals[i]);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<Interval> L = {{1,2},{3,7}, {5,10},{11,15}};
    Solution obj;
    vector<Interval> res = obj.merge(L);
    for(auto c:res) {
        cout<<c.start<<" "<<c.end<<endl;
    }
    cout<<endl;
    
    return 0;
}
