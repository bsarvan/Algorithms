//
//  main.cpp
//  BinarySearchTree
//
//  Created by Bharat Sarvan on 30/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
    
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};


TreeNode *BuildTree(vector<int> input, int &offset) {
    
    if (offset == input.size()) return nullptr;
    
    int val = input[offset++];
    
    if (input.empty() or val == -1) {
        return nullptr;
    }
    
    TreeNode *root = new TreeNode(val);
    root->left = BuildTree(input, offset);
    root->right = BuildTree(input, offset);

    return root;
}


void PrintTree(TreeNode* root) {
    if (root) {
        cout<<root->val<<" ";
        
        PrintTree(root->left);
        PrintTree(root->right);
    }
}


/*
 Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

 Example:

 Input:

    1
     \
      3
     /
    2

 Output:
 1

 Explanation:
 The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 */
class Solution {
public:
    
    void getMinimumDifferenceHelper(TreeNode *root, int &prev, int &min_diff) {
        if (!root) return;
        
        getMinimumDifferenceHelper(root->left, prev, min_diff);
        if (prev != -1) {
            min_diff = min(min_diff, abs(root->val - prev));
        }
        
        prev = root->val;
        
        getMinimumDifferenceHelper(root->right, prev, min_diff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int prev = -1;
        int min_diff = INT_MAX;
        getMinimumDifferenceHelper (root, prev, min_diff);
        return min_diff;
        
    }
};


int main(int argc, const char * argv[]) {
    vector<int> input = {1,-1,3,2};
    int offset = 0;
    TreeNode *root = BuildTree(input, offset);
    
    Solution sol;
    
    int result = sol.getMinimumDifference(root);
    
    cout<<result<<endl;
    
    
    
    return 0;
}
