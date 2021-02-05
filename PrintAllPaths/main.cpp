//
//  main.cpp
//  PrintAllPaths
//
//  Created by bsarvan on 23/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to check if given node is a leaf node or not
bool isLeaf(Node* node)
{
    return (node->left == nullptr && node->right == nullptr);
}

// Recursive function to find paths from root node to every leaf node
void printRootToleafPaths(Node* node, vector<int> &path)
{
    // base case
    if (node == nullptr)
        return;

    // include current node to path vector
    path.push_back(node->data);

    // if leaf node is found, print the path
    if (isLeaf(node))
    {
        for (int data: path)
            cout << data << " ";
        cout << endl;
    }

    // recur for left and right subtree
    printRootToleafPaths(node->left, path);
    printRootToleafPaths(node->right, path);

    // remove current node after left and right subtree are done
    path.pop_back();
}



//Iterative Solution


void printRootToleafPathIterative(Node* root)
{
    // create an empty stack to store a pair of tree node and
    // its path from the root node
    stack<pair<Node*, string>> stack;

    // push root node
    stack.push(make_pair(root, ""));

    // loop till stack is not empty
    while (!stack.empty())
    {
        // we pop a node from the stack and push the data to output stack
        pair<Node*, string> p = stack.top();
        stack.pop();

        // fetch current node
        Node* curr = p.first;
        string path = p.second;

        // add current node to the existing path
        string delim = (path == "") ? "\n" : "->";
        path += (delim + to_string(curr->data));

        // if leaf node, print the path
        if (curr->left == nullptr && curr->right == nullptr)
            cout << path;

        // push left and right child of popped node to the stack
        if (curr->right)
            stack.push(make_pair(curr->right, path));

        if (curr->left)
            stack.push(make_pair(curr->left, path));
    }
}

// Main function to print paths from root node to every leaf node
void printRootToleafPaths(Node* node)
{
    // vector to store root to leaf path
    vector<int> path;

    printRootToleafPaths(node, path);
}

// main function
int main()
{
    Node* root = nullptr;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7
           /     \
          8       9
    */

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->right->right = new Node(9);

    // print all root to leaf paths
    printRootToleafPaths(root);
    printRootToleafPathIterative(root);
    cout<<endl;
    return 0;
}
