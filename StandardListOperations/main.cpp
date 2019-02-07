//
//  main.cpp
//  StandardListOperations
//
//  Created by bsarvan on 14/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;


int main(int argc, const char * argv[]) {
    cout<<"Program to test standard C++ List operations"<<endl;
    
    list<int> *A;
    
    A = new list<int>[3];
    
    A[0].emplace_back(4);
    A[0].emplace_back(5);
    A[0].emplace_back(6);
    A[0].emplace_back(7);
    
    
    list<int>::iterator it;
    it = A[0].end();
    cout<<*it++<<endl;
    
    for(auto a:A[0]) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
