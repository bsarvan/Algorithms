//
//  main.cpp
//  PathSumIII
//
//  Created by Bharat Sarvan on 31/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 You are given a binary tree in which each node contains an integer value.

 Find the number of paths that sum to a given value.

 The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

 The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

 Example:

 root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

       10
      /  \
     5   -3
    / \    \
   3   2   11
  / \   \
 3  -2   1

 Return 3. The paths that sum to 8 are:

 1.  5 -> 3
 2.  5 -> 2 -> 1
 3. -3 -> 11

 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define null '#'

struct TreeNode {
   int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count;
    int k;
    unordered_map<int, int> currSum_freq;
public:
    
    void pathSumHelper(TreeNode* root, int curr_sum) {
        if (root == nullptr) {
            return;
        }
        
        // Compute the curr_sum
        curr_sum += root->val;
        
        // Check if the curr_sum is equal to target
        if (curr_sum == k) {
            count++;
        }
        
        if (currSum_freq.count(curr_sum - k) != 0) {
            count += currSum_freq[curr_sum - k];
        }
        
        currSum_freq[curr_sum]++;
        
        pathSumHelper(root->left, curr_sum);
        pathSumHelper(root->right, curr_sum);
        
        currSum_freq[curr_sum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        count = 0;
        k = sum;
        pathSumHelper(root, 0);
        return count;
    }
};


void BuildTree(TreeNode* &root, vector<int> preorder, int &offset) {
    if (offset == preorder.size()) {
        return;
    }
    
    int val = preorder[offset++];
    
    if (val == -1) {
        return;
    }
    
    root = new TreeNode(val);
    BuildTree(root->left, preorder, offset);
    BuildTree(root->right, preorder, offset);
}

void preOrder(TreeNode *root) {
    if (root) {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, const char * argv[]) {
   
//    vector<int> preorder = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    vector<int> preorder = {10, 5, 3, 3, -1, -1, -1, -2, -1, -1, 2, -1, 1, -3, -1, 11, -1, -1};
    
    int offset = 0;
    TreeNode *root = NULL;
    BuildTree(root, preorder, offset);
    
    preOrder(root);
    cout<<endl;
    
    Solution sol;
    int result = sol.pathSum(root, 8);
    
    cout<<"Result is "<<result<<endl;
    return 0;
}
