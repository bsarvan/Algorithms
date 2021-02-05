//
//  main.cpp
//  TreeDeleteNodeReturnForest
//
//  Created by bsarvan on 09/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

//Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* helper(TreeNode* root, std::unordered_set<int>& toDel, vector<TreeNode*>& result)     {
        if (!root) {
            return nullptr;
        }
        
        // Check if the node is a leaf node
        if (!root->left && !root->right) {
            // If node to deleted is a leaf node return nullptr
            if (toDel.find(root->val) != toDel.end()) {
                return nullptr;
            }
            
            return root;
        }
        
        // Traverse the left and right subtrees to find other deleted nodes
        TreeNode* left = helper(root->left, toDel, result);
        TreeNode* right = helper(root->right, toDel, result);
        
        if (!left) {
            root->left = nullptr;
        }
        
        if (!right) {
            root->right = nullptr;
        }
        
        if (toDel.find(root->val) != toDel.end()) {
            if (left) {
                result.push_back(left);
            }
            
            if (right) {
                result.push_back(right);
            }
            return nullptr;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) {
            return {};
        }

        std::unordered_set<int> toDel;

        for (auto d : to_delete) {
            toDel.insert(d);
        }

        vector<TreeNode*> result;

        TreeNode* ans = helper(root, toDel, result);
        if (ans) {
            result.push_back(ans);
        }
        return result;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
