//
//  main.cpp
//  UniquePtr
//
//  Created by bsarvan on 19/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <memory>
#include <cassert>
using namespace std;


struct D {

    D():data(0){ cout<<"This is D()"<<endl;}
    ~D() { cout<<"This is ~D()"<<endl;}
    void func() {cout<<"Data is - "<<data<<endl;}
    D(int d):data(d){ cout<<"This is D(int d)"<<endl;}
    int data;
    
};

struct E {
    E() { cout<<"This is E()"<<endl;}
    ~E() { cout<<"This is ~E()"<<endl;}
};
int main() {
    auto p = make_unique<D>(20);
    {
        auto q = make_unique<E>();
    }
    //auto r = move(p);
    //assert(!p);
    //p.reset();
    p->func();
    return 0;
}
