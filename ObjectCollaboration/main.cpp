//
//  main.cpp
//  ObjectCollaboration
//
//  Created by bsarvan on 23/05/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

class steering_ {
public:
    steering_() {
        cout<<"Creating Steering"<<endl;
    }
    void steerLeft() {
        cout<<"Steer Left"<<endl;
    }
    
    void steerRight() {
        cout<<"Steer Right"<<endl;
    }
};


class car {
    steering_ steering;
public:
    car():steering(steering_()) {
        cout<<"Creating Car"<<endl;
    }
    void turnLeft();
    void turnRight();
    
};

void car::turnLeft() {
    steering.steerLeft();
}

void car::turnRight() {
    steering.steerRight();
}

int main(int argc, const char * argv[]) {
    cout<<"Testing Object Collaboration"<<endl;
    car C;
    C.turnRight();
    C.turnLeft();
    return 0;
}
