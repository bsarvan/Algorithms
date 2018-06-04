//
//  main.cpp
//  ConstReference
//
//  Created by bsarvan on 29/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

void f(int &i) {};
void g(const int &i) {
    cout<<"Value is "<<i<<endl;
}

int main(int argc, const char * argv[]) {
    cout<<"Test program to validate const reference behavior"<<endl;
    g(1);
    
    return 0;
}
