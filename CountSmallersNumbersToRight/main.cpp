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
        this->val = val;
    }
};
    
int insertNode(TreeNode *root, int val) {
    TreeNode *curr = root;
    int thisCount = 0;
    
    while(true) {
        if(val <= curr->val) {
            cout<<"Left of "<<curr->val<<" "<<curr->count<<endl;
            curr->count++;
            if(curr->left == NULL) {
                curr->left = new TreeNode(val);
                cout<<"count Left - "<<curr->count<<endl;
                break;
            } else {
                curr = curr->left;
            }
        } else {
            cout<<"Right to "<<curr->val<<" "<<curr->count<<endl;
            thisCount += curr->count;
            if(curr->right == NULL) {
                curr->right = new TreeNode(val);
                cout<<"count Right - "<<curr->count<<endl;
                break;
            } else {
                curr = curr->right;
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
        res.insert(res.begin(),count);
    }
    return res;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Program to Count Smaller Numbers to Right of Array"<<endl;
//    vector<int> A = {5,2,8,1,7,0};
//    vector<int> A = {5,2,8,15,11,12,14,10};
    vector<int> A = {10,2,1,5,3};
    vector <int> R = countSmaller(A);
    
    for (auto c:R) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    return 0;
}
