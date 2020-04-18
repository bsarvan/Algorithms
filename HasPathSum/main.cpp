//
//  main.cpp
//  HasPathSum
//
//  Created by bsarvan on 14/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

//
//  main.cpp
//  BinaryTreeSearchRange
//
//  Created by bsarvan on 27/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 This problem was asked by Google.

 Given a binary search tree and a range [a, b] (inclusive), return the sum of the elements of the binary search tree within the range.

 For example, given the following tree:

     5
    / \
   3   8
  / \ / \
 2  4 6  10
 and the range [4, 9], return 23 (5 + 4 + 6 + 8).
 
 
 */
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
    Node(int x):val(x),left(NULL),right(NULL) {}
};

void printInorder(struct Node *root) {
    if (root) {
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
}

bool hasPathSum(struct Node *root, int sum) {
    stack<struct Node *> nodeStack;
    stack<int> sumStack;
    struct Node *curr = root;
    
    nodeStack.push(curr);
    sumStack.push(sum - root->val);
    
    while(!nodeStack.empty()) {
        curr = nodeStack.top();
        int curr_sum = sumStack.top();
        nodeStack.pop();
        sumStack.pop();
        
        cout<<"Node Val - "<<curr->val<<", Sum  - "<<curr_sum<<endl;
        if (curr->left == NULL && curr->right == NULL && curr_sum == 0) {
            return true;
        }
        
        if (curr->left) {
            nodeStack.push(curr->left);
            sumStack.push(curr_sum - curr->left->val);
        }
        
        if (curr->right) {
            nodeStack.push(curr->right);
            sumStack.push(curr_sum - curr->right->val);
        }
    }
    
    return false;
}


int main(int argc, const char * argv[]) {
    
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    int res = hasPathSum(root, 12);
    cout<<"Has a path with root to leaf sum of 12 - "<<res<<endl;
    
    return 0;
}
