//
//  main.cpp
//  SolveEquation
//
//  Created by Bharat Sarvan on 24/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void ApplyOps(stack<int> &values, stack<char> &ops) {
    int y = values.top();
    values.pop();
    int x = values.top();
    values.pop();
    
    int result = 0;
    if (ops.top() == '+') {
        result = x + y;
    } else if (ops.top() == '-') {
        result = x - y;
    }
    
    ops.pop();
    values.push(result);
    return;
    
    
}


void SolveEquation(string s) {
    stack<int> values;
    stack<char> ops;
    
    for (auto c : s) {
        if (isdigit(c)) {
            values.push(c - '0');
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while(!ops.empty() and ops.top() != '(') {
                ApplyOps(values, ops);
            }
            
            ops.pop();
            
        } else if (c == ' ') {
            continue;
        } else {
            ops.push(c);
        }
    }
    
    while(!ops.empty()) {
        ApplyOps(values, ops);
    }
    
    cout<<values.top()<<endl;
}

int main(int argc, const char * argv[]) {
    cout<<"Algorithm to solve arithmatic equation with braces"<<endl;
    string equation = "(9 + 2) - 4";
    
    SolveEquation(equation);
    
    return 0;
}
