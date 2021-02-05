//
//  main.cpp
//  FindMaxSimulataneousEvents
//
//  Created by Bharat Sarvan on 08/08/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

// Algorithm to find the maximum simultaneous events that can occur in an interval

#include <iostream>
#include <vector>
using namespace std;


struct Event {
    int start;
    int end;
};

struct Endpoint {
    
    bool operator <(const Endpoint &that) const {
        bool ret = (time != that.time ? time < that.time : isStart && !that.isStart);
        cout<<"Comparing "<<that.time<<" and "<<time<<", Comparison result "<<ret<<endl;
        return ret;
    }
    
    int time;
    bool isStart;
};


void printEndpoint(vector<Endpoint> E) {
    cout<<"Endpoints list - "<<endl;
    for (auto e:E) {
        cout<<"Time - "<<e.time<<", isStart - "<<e.isStart<<endl;
    }
}

int findMaxSimulataneuosEvents(vector<Event> events) {
    vector<Endpoint> E;
    
    for (auto e:events) {
        E.emplace_back(Endpoint{e.start, true});
        E.emplace_back(Endpoint{e.end, false});
    }
    
    printEndpoint(E);
    
    sort(E.begin(), E.end());
    
    printEndpoint(E);
    
    int maxSimulataneousEvents = 0;
    int numSimultatneousEvents = 0;
    for (auto e:E) {
        if (e.isStart) {
            numSimultatneousEvents++;
            maxSimulataneousEvents = max(maxSimulataneousEvents, numSimultatneousEvents);
        } else {
            numSimultatneousEvents--;
        }
    }
    
    return maxSimulataneousEvents;
}

int main(int argc, const char * argv[]) {
    
//    vector<Event> events = {Event{0,3}, Event{1,5}, Event{1,3}, Event{3,8}, Event{5,9}};
    vector<Event> events = {{4,6}, {3,4}, {6,9}};
    cout<<"Algorithm to find the maximum simulataneuos events occuring in a time interval"<<endl;
    int maxSimulataneousEvents = findMaxSimulataneuosEvents(events);
    
    cout<<"Max Simultaneous Events - "<<maxSimulataneousEvents<<endl;
    
    return 0;
}
