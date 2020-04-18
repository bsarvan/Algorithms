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

struct event {
    long int timestamp;
    int count;
    bool type;
};

const vector<event> Events = {
    {1526579928,3,0},
    {1526580382,2,1},
    {1526579938,6,0},
    {1526579943,1,0},
    {1526580345,5,1},
    {1526580351,3,1}
};


int main(int argc, const char * argv[]) {
    cout<<"Program to find the busiest period in a building"<<endl;
    
    int num_people = 0, max_num_people = 0;
    
    for (int i=0;i<Events.size();i++) {
        if (Events[i].type == 0) {
            num_people++;
        } else {
            num_people--;
        }
        
        if (num_people > max_num_people) {
            max_num_people = num_people;
            cout<<"Start Time - "<<Events[i].timestamp<<", End Time - "<<Events[i + 1].timestamp<<endl;
        }
    }
    return 0;
}
