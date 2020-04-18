//
//  main.cpp
//  ParseEquation
//
//  Created by bsarvan on 17/10/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

void apply_ops(stack<int> val, stack<char> ops) {
    char op = ops.top();
    ops.pop();
    
    auto left = val.top();
    val.pop();
    auto right = val.top();
    val.pop();
    
    if (op == '+') {
        val.emplace(left + right);
    } else if (op == '-') {
        val.emplace(left - right);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
