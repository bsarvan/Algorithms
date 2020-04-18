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
    Singleton(string s):name(s) {
        cout<<"Single Constructor"<<endl;
        cout<<"Instance - "<<instance<<endl;
    }
    
    string name;
public: 
    static Singleton *getInstance(string s) {
        if(instance == NULL) {
            cout<<"Object is NULL. Creating new one"<<endl;
            instance  = new Singleton(s);
            return instance;
        }
        cout<<"Returning existing instance"<<endl;
        return instance;
    }
    void print() {
        cout<<"I'm "<<name<<endl;
    }
};

Singleton *Singleton::instance = NULL;

void foo(void) {
    Singleton *obj = Singleton::getInstance("Singleton");
    obj->print();
    return;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to test Singleon Design Pattern"<<endl;
    foo();
    Singleton *obj2  = Singleton::getInstance("NewSingleTon");
    obj2->print();
    
    return 0;
}
