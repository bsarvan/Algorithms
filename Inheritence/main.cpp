//
//  main.cpp
//  Inheritence
//
//  Created by bsarvan on 30/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//


#include <iostream>
using namespace std;

class Base
{
    int basedata;
public:
    Base()
    {
        cout<<"In Base"<<endl;
    }
    
    Base(int data):basedata(data){ cout<<"In Base(int)"<<endl;}
    
    ~Base()
    {
        cout<<"In ~Base"<<endl;
    }
    
    virtual void basic()
    {
        cout<<"Basic Feature"<<endl;
    }
    
    virtual void basic(int a)
    {
        cout<<"A - "<<a<<", Base Class"<<endl;
    }
};


class DA:public Base
{
public:
    DA()
    {
        cout<<"In DA"<<endl;
    }
    
    DA(int d):Base(d), daData(d){ cout<<"In DA(int)"<<endl; }
    
    ~DA()
    {
        cout<<"In ~DA"<<endl;
    }
 

    void basic()
    {
        cout<<"Basic Feature DA"<<endl;
    }
    
private:
    int daData;
    
};

void myinterface (Base *b)
{
    b->basic();
}


int main()
{
    //unique_ptr<Base> base = make_unique<DA>(9);
    Base *d = new DA();
    //DA d;
    
    //b.basic();
    //d.basic();
    //base->basic();
    //d.basic();
    //myinterface(d);
    
    delete d;
    return 0;
}

