//
//  main.cpp
//  CountPathsWithSum
//
//  Created by bsarvan on 06/03/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int key):val(key),left(NULL), right(NULL) {};
};

void BuildTree(struct TreeNode *&root, vector<int> V, int &offset) {
    if (offset == V.size()) return;
    
    int key = V[offset++];
    
    if (key == -1) {
        return;
    }
    root = new TreeNode(key);
    BuildTree(root->left, V, offset);
    BuildTree(root->right, V, offset);
    return;
}

void preOrder(TreeNode *root) {
    if (root) {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, const char * argv[]) {
    TreeNode *root = NULL;
    
    vector<int> input = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    int offset = 0;
    BuildTree(root, input, offset);
    
    preOrder(root);
    cout<<endl;
    return 0;
}
