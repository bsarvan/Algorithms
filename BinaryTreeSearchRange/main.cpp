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

void SumRange(struct Node *root, int low, int high, int &partialSum) {
    if (root == NULL) {
        return;
    }
    
    if ((low <= root->val) && (root->val <= high)) {
        partialSum += root->val;
    }
    
    SumRange(root->left, low, high, partialSum);
    SumRange(root->right, low, high, partialSum);
}


int sumRange_v2(struct Node *root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    
    if (low <= root->val && root->val<=high) {
        return (sumRange_v2(root->left, low, high) + sumRange_v2(root->right, low, high) + root->val);
    }
    
    if (low > root->val) {
        sumRange_v2(root->right, low, high);
    }
    
    if (high < root->val) { 
        sumRange_v2(root->left, low, high);
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    
    
    printInorder(root);
    
    cout<<endl;
    
    
    int sum = 0;
    
//    SumRange(root,4, 9, sum);
//
//    cout<<"Sum of Nodes within Range - "<<sum<<endl;
    cout<<"Sum of Nodes within Range on new function - "<<sumRange_v2(root, 4, 9)<<endl;
    cout<<endl;
    
    return 0;
}
