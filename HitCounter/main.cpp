//
//  main.cpp
//  HitCounter
//
//  Created by bsarvan on 22/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

/* Record a hit.
 @param timestamp - The current timestamp (in
 seconds granularity). */

class HitCounter {
public:
    void hit(int timestamp)
    {
        v.push_back(timestamp);
    }

    // Time Complexity : O(1)

    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in
     seconds granularity). */
    int getHits(int timestamp)
    {
        int i;
        for (i = 0; i < v.size(); ++i) {
            if (v[i] > timestamp - 300) {
                cout<<"Breaking for i "<<i<<endl;
                break;
            }
        }
        cout<<"Returning - "<<i<<endl;
        return v.size() ;
    }
};


// Time Complexity : O(n)

int main() {
    cout<<"Testing Hit Counter"<<endl;
    
    HitCounter counter;
    
    counter.hit(1);
    counter.hit(2);
    counter.hit(3);
    cout<<counter.getHits(300)<<endl;
    
    
    
    return 0;
}
