//
//  main.cpp
//  DiameterOfTree
//
//  Created by bsarvan on 12/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

// C++ program to find diameter of a binary tree
// using DFS.
#include <iostream>
#include <limits.h>
#include <list>
using namespace std;

// Used to track farthest node.
int x;

// Sets maxCount as maximum distance from node.
void dfsUtil(int node, int count, bool visited[],
                int& maxCount, list<int>* adj)
{
    visited[node] = true;
    count++;
//    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
    for (auto adjacent_node : adj[node]) {
        if (!visited[adjacent_node]) {
            if (count >= maxCount) {
                maxCount = count;
                x = adjacent_node;
            }
            dfsUtil(adjacent_node, count, visited, maxCount, adj);
        }
    }
}

// The function to do DFS traversal. It uses recursive
// dfsUtil()
void dfs(int node, int n, list<int>* adj, int& maxCount)
{
    bool visited[n + 1];
    int count = 0;

    // Mark all the vertices as not visited
    for (int i = 1; i <= n; ++i)
        visited[i] = false;

    // Increment count by 1 for visited node
    dfsUtil(node, count + 1, visited, maxCount, adj);
}

// Returns diameter of binary tree represented
// as adjacency list.
int diameter(list<int>* adj, int n)
{
    int maxCount = INT_MIN;

    /* DFS from a random node and then see
    farthest node X from it*/
    dfs(1, n, adj, maxCount);

    /* DFS from X and check the farthest node
    from it */
    dfs(x, n, adj, maxCount);

    return maxCount;
}



//====================================================================================

// Find the Diameter of the Tree using the Height

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
    TreeNode (int v):val(v), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int ComputeDiameter(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        
        int lheight = ComputeDiameter(root->left, ans);
        int rheight = ComputeDiameter(root->right, ans);
        
        ans = max(ans, lheight + rheight + 1);
        
        return 1 + max(lheight, rheight);
    }
};




/* Driver program to test above functions*/
int main()
{
    int n = 5;

    /* Constructed tree is
        1
        / \
        2 3
    / \
    4 5 */
    list<int>* adj = new list<int>[n + 1];

    /*create undirected edges */
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(2);


    /* maxCount will have diameter of tree */
    cout << "Diameter of the given tree is "
        << diameter(adj, n) << endl;
    
    // Binary Tree
    
    TreeNode *root = new TreeNode(1);
    
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol;
    int ans = 0;
    sol.ComputeDiameter(root, ans);
    
    cout<<"Diameter of Binary Tree is "<<ans<<endl;
    
    
    return 0;
}
