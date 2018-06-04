//
//  main.cpp
//  Singleton
//
//  Created by bsarvan on 30/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

class Singleton {
    static Singleton *instance;
public:
    Singleton() {
        cout<<"singleton()"<<endl;
    }
    
    static Singleton *getInstance() {
        if(instance == NULL) {
            instance  = new Singleton;
        }
        return instance;
    }
};

Singleton *Singleton::instance = NULL;

void foo(void) {
    Singleton::getInstance();
    return;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to test Singleon Design Pattern"<<endl;
    foo();
    return 0;
}
