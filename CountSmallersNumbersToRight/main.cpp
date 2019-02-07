//
//  main.cpp
//  CountSmallersNumbersToRight
//
//  Created by bsarvan on 09/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TreeNode;

class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    int count = 1;
    TreeNode(int val) {
        val = val;
    }
};
    
int insertNode(TreeNode *root, int val) {
    int thisCount = 0;
    while(true) {
        if(val <= root->val) {
            root->count++;
            if(root->left == NULL) {
                root->left = new TreeNode(val);
                break;
            } else {
                root = root->left;
            }
        } else {
            thisCount += root->count;
            if(root->right == NULL) {
                root->right = new TreeNode(val);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return thisCount;
}

vector<int> countSmaller(vector<int> nums) {
    vector<int> res;
    
    TreeNode *root = new TreeNode(nums[nums.size() - 1]);
    
    res.emplace_back(0);
    
    for(int i = nums.size() - 2; i >= 0; i--) {
        cout<<"Insert Number "<<nums[i]<<endl;
        int count = insertNode(root, nums[i]);
        cout<<"Emplacing "<<count<<endl;
        res.emplace_back(count);
    }
    return res;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Program to Count Smaller Numbers to Right of Array"<<endl;
    vector<int> A = {5,2,6,1};
    vector <int> R = countSmaller(A);
    
    for (auto c:R) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    return 0;
}
