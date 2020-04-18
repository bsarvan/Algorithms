//
//  main.cpp
//  ReversePolishNotation
//
//  Created by bsarvan on 27/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string S = "54+6+";
    stack<int> SS;
    
    for (auto c:S) {
        if (c == '+') {
            int x = SS.top();
            SS.pop();
            int y = SS.top();
            SS.pop();
            
            SS.push(x + y);
        } else {
            SS.push(c - '0');
        }
    }
    
    cout<<"Result is "<<SS.top()<<endl;
    SS.pop();
    return 0;
}
