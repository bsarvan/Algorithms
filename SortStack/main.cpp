//
//  main.cpp
//  SortStack
//
//  Created by bsarvan on 20/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


int main(int argc, const char * argv[]) {
    cout<<"Program to Sort Stack elements"<<endl;
    stack<int> s1;
    stack<int> s2;
    
    s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.push(1);
    
    while(!s1.empty()) {
        int tmp = s1.top();
        s1.pop();
        while(!s2.empty() && s2.top() > tmp){
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(tmp);
    }
    
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    
    while(!s1.empty()) {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return 0;
}
