//
//  main.cpp
//  ConstructorConversion
//
//  Created by bsarvan on 14/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

class One {
    int x;
public:
    One(){
        cout<<"Constructor of One"<<endl;
    }
    One(int a):x(a){}
    virtual void print() {
        cout<<"I'm One - "<<x<<endl;
    }
};

class Two:public One {
public:
    Two(const One&) {
        cout<<"Constructor of Two"<<endl;
    }
    
    void print() {
        cout<<"I'm Two"<<endl;
    }
};

void f(Two obj) {
    obj.print();
}




int main(int argc, const char * argv[]) {
    cout<<"Testing Automatic Type Conversion using Constructors"<<endl;
    One one;
    
    f(one);
    One one1(90);
    one1.print();
    one1 = 100;
    one1.print();
    
    
    return 0;
}
