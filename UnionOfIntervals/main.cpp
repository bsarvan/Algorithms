//
//  main.cpp
//  UnionOfIntervals
//
//  Created by bsarvan on 11/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
private:
    struct Endpoint {
        bool isClosed;
        int val;
    };
    
public:
    bool operator<(const Interval &i) const {
        if (left.val != i.left.val) {
            return (left.val < i.left.val);
        }
        
        return (left.isClosed && !i.left.isClosed);
    }
    
    Endpoint left, right;
};

vector<Interval> computeUnionOfIntervals (vector<Interval> intervals) {
    if (intervals.empty()) {
        return {};
    }
    
    sort(intervals.begin(),intervals.end());
    Interval curr(intervals.front());
    for(int i=1; i<intervals.size();i++) {
        if (intervals[i].left.val < curr.right.val ||
           (intervals[i].left.val == curr.right.val ||
           (intervals[i].left.isClosed || curr.right.isClosed))) {
               
               if ( is)
               
           }
            
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
