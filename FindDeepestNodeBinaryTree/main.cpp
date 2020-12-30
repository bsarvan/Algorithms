//
//  main.cpp
//  FindDeepestNodeBinaryTree
//
//  Created by Bharat Sarvan on 26/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

// A C++ program to find value of the deepest node
// in a given binary tree
#include <iostream>
using namespace std;

// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
    
    Node (int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new node
Node *newNode(int data)
{
    return new Node(data);
}

// maxLevel : keeps track of maximum level seen so far.
// res : Value of deepest node so far.
// level : Level of root
void find(Node *root, int level, int &maxLevel, int &res)
{
    
    if (root != NULL)
    {
        cout<<"A Level at node - "<<root->data<<", Level - "<<level<<endl;
        find(root->left, ++level, maxLevel, res);
        cout<<"B Level at node - "<<root->data<<", Level - "<<level<<endl;

        // Update level and resue
        if (level > maxLevel)
        {
            res = root->data;
            maxLevel = level;
        }

        find(root->right, level, maxLevel, res);
    }
}

// Returns value of deepest node
int deepestNode(Node *root)
{
    // Initialze result and max level
    int res = -1;
    int maxLevel = -1;

    // Updates value "res" and "maxLevel"
    // Note that res and maxLen are passed
    // by reference.
    find(root, 0, maxLevel, res);
    return res;
}

// Driver program
int main()
{
    cout<<"Algorithm to find the deepest node in a binary tree"<<endl;
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
//    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->right->right->right = newNode(9);
    int result = deepestNode(root);
    cout << "Deepest Node in tree is "<<result<<endl;
    return 0;
}
