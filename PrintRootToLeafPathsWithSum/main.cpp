//
//  main.cpp
//  PrintRootToLeafPathsWithSum
//
//  Created by bsarvan on 06/03/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

// C++ program to print all paths begiinning with
// root and sum as given sum
#include <iostream>
#include <vector>
using namespace std;





//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void pathSumUtil(TreeNode *root, int target, int sum_so_far, vector<int> &path, vector<vector<int>> &paths) {
        if (root == NULL) {
            return;
        }
        
        sum_so_far = sum_so_far + root->val;
        path.emplace_back(root->val);
        
        if (root->left == NULL && root->right == NULL) {
            if (sum_so_far == target) {
                paths.emplace_back(path);
            }
        }
        
        pathSumUtil(root->left, target, sum_so_far, path, paths);
        pathSumUtil(root->right, target, sum_so_far, path, paths);
        
        path.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        int sum_so_far = 0;
        
        pathSumUtil(root, sum, sum_so_far, path, paths);
        
        return paths;
        
    }
};



// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}


void printPathsUtil(Node* curr_node, int sum,
            int sum_so_far, vector<int> &path)
{
    if (curr_node == NULL) {
        return;
    }

    // add the current node's value
    sum_so_far += curr_node->key;

    // add the value to path
    path.push_back(curr_node->key);

    // print the required path
    if (sum_so_far == sum )
    {
        cout << "Path found: ";
        for (int i=0; i<path.size(); i++)
            cout << path[i] << " ";

        cout << endl;
    }


    printPathsUtil(curr_node->left, sum, sum_so_far, path);
    printPathsUtil(curr_node->right, sum, sum_so_far, path);


    // Remove the element from path vector
    // before moving back to parent
    path.pop_back();
}

// Wrapper over printPathsUtil
void printPaths(Node *root, int sum)
{
    vector<int> path;
    printPathsUtil(root, sum, 0, path);
}

// Driver program
int main ()
{
    
    cout<<"Algorith to find all the root to leaf path that are equal to a given sum"<<endl;
    /* 10
    /     \
    28     13
        /     \
        14     15
        / \     / \
    21 22 23 24*/
    Node *root = newNode(10);
    root->left = newNode(28);
    root->right = newNode(13);

    root->right->left = newNode(14);
    root->right->right = newNode(15);

    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);

    int sum = 38;

    printPaths(root, sum);

    return 0;
}
