//
//  main.cpp
//  PureVirtualDestructor
//
//  Created by bsarvan on 28/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

class Pet {
public:
    virtual ~Pet() = 0;
};

Pet::~Pet() {
    cout<<"~Pet"<<endl;
}

class Dog:public Pet
{
public:
    ~Dog() {
        cout<<"~Dog"<<endl;
    }
    
};

int main(int argc, const char * argv[]) {
    cout<<"Program to test Pure Virtual Destructors"<<endl;
    Dog *d = new Dog();
    delete d;
    
    return 0;
}
