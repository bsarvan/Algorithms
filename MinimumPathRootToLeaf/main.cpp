//
//  main.cpp
//  MinimumPathRootToLeaf
//
//  Created by Bharat Sarvan on 15/08/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int val;
    struct Node *left , *right;
    Node (int v) {
        this->val = v;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTree(Node *root) {
    if (root) {
        printTree(root->left);
        cout<<root->val<<" ";
        printTree(root->right);
    }
}


void minimumSumPathUtil(Node *root, int sumTillNow, int &minSoFar) {
    if (root == NULL) {
        return;
    }
    
    sumTillNow += root->val;
    
    if (root->left == NULL && root->right == NULL) {
        minSoFar = min(minSoFar, sumTillNow);
    }
    
    minimumSumPathUtil(root->left, sumTillNow, minSoFar);
    minimumSumPathUtil(root->right, sumTillNow, minSoFar);
    return;
}

int minimumSumPath(Node *root) {
    int minSoFar = INT_MAX;
    minimumSumPathUtil(root, 0, minSoFar);
    return (minSoFar);
}

int main(int argc, const char * argv[]) {

    cout<<"Algorithm to find the minimum sum path from root to leaf"<<endl;
    Node *root = new Node(5);
    
    root->left = new Node(1);
    root->left->left = new Node (2);
    root->right = new Node(-2);
    root->right->right = new Node(1);
    root->right->left = new Node(-1);
    
    printTree(root);
    cout<<endl;
    int minSum = minimumSumPath(root);
    cout<<minSum<<endl;
    
    return 0;
}
