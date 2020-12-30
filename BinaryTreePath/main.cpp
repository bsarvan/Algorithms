//
//  main.cpp
//  BinaryTreePath
//
//  Created by bsarvan on 12/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left, *right;
    
    TreeNode(int v):val(v),left(NULL),right(NULL) {}
};


void printInorder(TreeNode *root) {
    TreeNode *curr = root;
    stack<TreeNode *> S;
    
    cout<<"Inorder Trace of Tree - ";
    while(!S.empty() || curr) {
        if (curr) {
            S.push(curr);
            curr = curr->left;
        } else {
            curr = S.top();
            S.pop();
            cout<<curr->val<<" ";
            curr = curr->right;
        }
    }
    
    cout<<endl;
}


void BinaryTreePathHelper(TreeNode *root, string path, vector<string> &paths) {
    if (root) {
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            paths.emplace_back(path);
        } else {
            BinaryTreePathHelper(root->left, path, paths);
            BinaryTreePathHelper(root->right, path, paths);
        }
    }
}

vector<string> BinaryTreePath(TreeNode *root) {
    vector<string> paths;
    BinaryTreePathHelper(root,"", paths);
    return paths;
}

TreeNode *UpsideDown(TreeNode *root) {
 
    if (root == NULL) {
        return NULL;
    }
    
    TreeNode *parent = root;
    TreeNode *L = root->left;
    TreeNode *R = root->right;
    
    if (L) {
        TreeNode *ret = UpsideDown(L);
        cout<<"Processing Node "<<root->val<<endl;
        cout<<"ret - "<<ret<<endl;
        L->left = R;
        L->right = parent;
        return ret;
    }
    return root;
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || !root->left) {
        return root;
    }
    
    TreeNode* newRoot = upsideDownBinaryTree(root->left);
    cout<<"root - "<<root->val<<", root->left - "<<root->left<<", root->right - "<<root->right<<endl;
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    
    cout<<"New Root - "<<newRoot->val<<endl;
    return newRoot;
}



int main(int argc, const char * argv[]) {
    
    TreeNode *root = new TreeNode(1);
    vector<string> paths;
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    //root->right->left = new TreeNode(6);
    //root->right->right = new TreeNode(7);
    
//    paths = BinaryTreePath(root);
//
//    for(auto p : paths) {
//        cout<<p<<endl;
//    }
    
    printInorder(root);
    TreeNode *newRoot = upsideDownBinaryTree(root);
    printInorder(newRoot);
    
    return 0;
}
