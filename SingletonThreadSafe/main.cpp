//
//  main.cpp
//  SingletonThreadSafe
//
//  Created by bsarvan on 30/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

class Foo {
public:
    static Foo* Instance();
    
private:
    
    Foo() {init();}
    void init() { cout << "init done." << endl;} // your init cache function.
    static atomic<Foo*> pinstance;
    static mutex m_;
};

atomic<Foo*> Foo::pinstance { nullptr };

std::mutex Foo::m_;

Foo* Foo::Instance() {
    if(pinstance == nullptr) {
        lock_guard<mutex> lock(m_);
        if(pinstance == nullptr) {
            pinstance = new Foo();
        }
    }
    return pinstance;
}



int main() {
    Foo* foo1 = Foo::Instance();
    Foo* foo2 = Foo::Instance();
    return 0;
}


