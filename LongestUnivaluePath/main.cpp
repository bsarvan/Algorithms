//
//  main.cpp
//  LongestUnivaluePath
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>


int lup;

int longestUnivaluePath(TreeNode* root) {
    int lup = 0;
    if (root) dfs(root, lup);
    return lup;
}

private:
int dfs(TreeNode* node, int& lup) {
    int l = node->left ? dfs(node->left, lup) : 0;
    int r = node->right ? dfs(node->right, lup) : 0;
    
    int resl = node->left && node->left->val == node->val ? l + 1 : 0;
    int resr = node->right && node->right->val == node->val ? r + 1 : 0;
    
    lup = max(lup, resl + resr);
    return max(resl, resr);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
