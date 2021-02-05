//
//  main.cpp
//  StackAlgorithms
//
//  Created by Bharat Sarvan on 02/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack {
    int top;
    vector<int> data;
    int size;
public:
    Stack(int S) {
        this->top = -1;
        this->size = S;
        this->data.resize(S, -1);
    }
    
    void Push(int val);
    int Top(void);
    void Pop(void);
    bool isEmpty(void);
    void DisplayStack(void);
};

void Stack::DisplayStack(void) {
    if (isEmpty()) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    
    cout<<"Contents of the Stack - "<<endl;
    for (auto &d : data) {
        if (d != -1) {
            cout<<d<<endl;
        }
    }
    cout<<"=============="<<endl;
}

bool Stack::isEmpty(void) {
    return (top == -1);
}

void Stack::Push(int val) {
    if (top == size - 1) {
        cout<<"Stack is full"<<endl;
        return;
    }
    
    top++;
    data[top] = val;
    return;
}

int Stack::Top(void) {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    
    return data[top];
}

void Stack::Pop(void) {
    if (top == -1) {
        cout<<"Stack is empty"<<endl;
        return;
    }

    data[top] = -1;
    top--;
}



void sortedInset(stack<int> &S, int elem) {
    if (S.empty() || S.top() < elem) {
        S.push(elem);
    } else {
        int temp = S.top();
        S.pop();
        sortedInset(S, elem);
        S.push(temp);
    }
    return;
}


int main(int argc, const char * argv[]) {
    
    //  Stack Implementation using Array
    Stack S(5);
    
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.DisplayStack();
    
    //================================================
    stack<int> ST;
    
    sortedInset(ST, 3);
    sortedInset(ST, 4);
    sortedInset(ST, 5);
    sortedInset(ST, 2);
    
    cout<<"Stack - "<<endl;
    while(!ST.empty()) {
        cout<<ST.top()<<endl;
        ST.pop();
    }
    cout<<endl;
    
    //================================================
    
    
    
    return 0;
}
