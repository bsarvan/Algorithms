//
//  main.cpp
//  GreedyIntervalCoveringProblem
//
//  Created by bsarvan on 14/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Interval
{
    int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.end < i2.end);
}

int main()
{
    vector<Interval> arr =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = arr.size();
    
    // sort the intervals in increasing order of
    // start time
    sort(arr.begin(),arr.end(), compareInterval);
    
    cout << "Intervals sorted by end time : \n";
    for (int i=0; i<n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
        << "] ";
    
    cout<<endl;
    
    vector<int> visits;
    
    int last_visit_time = arr.front().end;
    visits.emplace_back(last_visit_time);
    for( auto c:arr) {
        if(c.start > last_visit_time) {
            last_visit_time = c.end;
            visits.emplace_back(last_visit_time);
        }
    }
    
    cout<<"Visits Planned - "<<endl;
    
    for (auto a:visits) {
        cout<<a<<endl;
    }
    
    return 0;
}
