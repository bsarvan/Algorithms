//
//  main.cpp
//  BusiestPeriod
//
//  Created by bsarvan on 19/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> Type = {
    "ENTRY",
    "EXIT"
};

struct event {
    long int timestamp;
    int count;
    bool type;
    
    bool operator<(const event &E) const {
        return (timestamp < E.timestamp);
    }
    
    void printData() {
        cout<<timestamp<<" - "<<count<<" - "<<Type[type]<<endl;
    }
};

const vector<event> Events = {
    {1526579928,3,0},
    {1526580382,2,1},
    {1526579938,6,0},
    {1526579943,1,0},
    {1526580345,5,1},
    {1526580351,3,1}
};

void printTable(vector<event> T) {
    for (auto t:T) {
        t.printData();
    }
}

struct busiestPeriod {
    int start;
    int end;
    int maxVisitors;
    
    busiestPeriod():start(0), end(0), maxVisitors(0) {};
};


vector<int> findBusyPeriod(vector<event> events) {
    busiestPeriod busyPeriod;
    int visitors = 0;
    
    for (auto &event : events) {
        visitors = event.type == ENTRY ? visitors + event.count : visitors - event.count;
        
        if (visitors > busyPeriod.maxVisitors) {
            busyPeriod.start = event.timestamp;
            busyPeriod.maxVisitors = visitors;
        }
    }
    
}

vector<double> findBusiestPeriod(vector<event> Events) {
    vector<double> result;
    vector<event> startTimes;
    vector<event> endTimes;
    
    for (auto E:Events) {
        if (E.type == 0) {
            startTimes.emplace_back(E);
        } else {
            endTimes.emplace_back(E);
        }
    }
    
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());
    
    cout<<"Start Times Table - "<<endl;
    printTable(startTimes);
    cout<<"End Times Table - "<<endl;
    printTable(endTimes);
    
    
    int i = 0;
    int j = 0;
    
    while(i < startTimes.size() && j < endTimes.size()) {
        
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find the busiest period in a building"<<endl;
//
//    int num_people = 0, max_num_people = 0;
//
//    for (int i=0;i<Events.size();i++) {
//        if (Events[i].type == 0) {
//            num_people++;
//        } else {
//            num_people--;
//        }
//
//        if (num_people > max_num_people) {
//            max_num_people = num_people;
//            cout<<"Start Time - "<<Events[i].timestamp<<", End Time - "<<Events[i + 1].timestamp<<endl;
//        }
//    }
    
    findBusiestPeriod(Events);
    
    return 0;
}
