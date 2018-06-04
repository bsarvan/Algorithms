//
//  main.cpp
//  BST
//
//  Created by bsarvan on 20/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <memory>
#include <queue>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

int height(struct node *root){
    if(root == NULL)
        return -1;
    
    return (max(height(root->right),height(root->left)) + 1);
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}

void levelOrderTraversal(struct node *root) {
    
    if(root == NULL)
        return;
    
    queue<struct node *> q;
    q.push(root);
    while(!q.empty()) {
        struct node *tmp = q.front();
        cout<<tmp->key<<" ";
        q.pop();
        
        if (tmp->left)
            q.push(tmp->left);
        
        if(tmp->right)
            q.push(tmp->right);
    }
}


int MaxNodeAtLevel(struct node *root){
    queue<struct node *> q;
    q.push(root);
    
    int level_no = 0;
    int level = 0;
    size_t max = 0;
    while(1){
        
        cout<<"Size at level "<<level<<" "<<q.size()<<endl;
        size_t NodeCount = q.size();
        
        if (NodeCount == 0)
            break;
      
        if (NodeCount > max) {
            max = NodeCount;
            level_no = level;
        }
        while(NodeCount > 0){
            struct node *p = q.front();
            q.pop();
            if(p->left)
                q.push(p->left);
            
            if(p->right)
                q.push(p->right);
            
            NodeCount--;
        }
        level++;
        
    }
    return level_no;
    
}


void createLinkedList(struct node *root, unordered_map<int,list<struct node *>> &lists, int level) {
    if (root == NULL){
        return;
    }
    list<struct node*> nodeList;
    unordered_map<int, list<struct node *>>::iterator iter = lists.find(level);
    if(iter == lists.end()) {
        nodeList.emplace_back(root);
        lists.emplace(level,nodeList);
    } else {
        list<struct node*> &nodeList = iter->second;
        nodeList.emplace_back(root);
    }
    
    createLinkedList(root->left, lists, level+1);
    createLinkedList(root->right,lists, level+1);
    return;
}


void buildNodeLevelList(struct node *root) {
    unordered_map<int, list<struct node *>> ll;
    createLinkedList(root,ll, 0);
    
    
    unordered_map<int, list<struct node *>>::iterator iter;
    for(iter = ll.begin(); iter !=ll.end();iter++){
        cout<<"Nodes at level - "<<iter->first<<" - ";
        list<struct node*>::iterator it;
        for(it = iter->second.begin();it != iter->second.end();it++){
            struct node *n = *it;
            cout<<n->key<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void InOrderTraversal(struct node *root) {
    stack<struct node *> q;
    struct node* curr = root;
    
    while(!q.empty() || curr) {
        if(curr) {
            q.push(curr);
            curr = curr->left;
        } else {
            curr = q.top();
            q.pop();
            cout<<curr->key<<" ";
            curr = curr->right;
        }
    }
}



void PreOrderTraversal(struct node *root){
    stack<struct node *> q;
    struct node *curr;
    q.push(root);
    
    while(!q.empty()) {
        curr = q.top();
        q.pop();
        if(curr != nullptr) {
            cout<<curr->key<<" ";
            q.push(curr->right);
            q.push(curr->left);
        }
    }
    cout<<endl;
    return;
}

void preorder(struct node *root) {
    if (root == nullptr)
        return;
    
    cout<<root->key<<" ";
    
    preorder(root->left);
    preorder(root->right);
}

/* Given a binary tree, print its nth nodes of inorder*/
void NthInorder(struct node* node, int n)
{
    static int count = 0;
    if (node == NULL)
        return;
    
    if (count <= n) {
        
        /* first recur on left child */
        NthInorder(node->left, n);
        count++;
        
        // when count = n then print element
        if (count == n)
            printf("%d ", node->key);
        
        /* now recur on right child */
        NthInorder(node->right, n);
    }
}


struct node* findLCA(struct node *root, struct node *s, struct node *b) {
    struct node *p = root;
    while(p->key < s->key || p->key > b->key) {
        cout<<"P - "<<p->key<<endl;
        while(p->key < s->key) {
            cout<<"Traversing right"<<endl;
            p = p->right;
            cout<<"p After Right Move - "<<p->key<<endl;
        }
        
        while(p->key > b->key){
            cout<<"Traversing left"<<endl;
            p = p->left;
            cout<<"p After Left Move - "<<p->key<<endl;
        }
    }
    return p;
}

struct node* FindMin(struct node *root) {
    while(root->left != NULL)
       root = root->left;
    
    return root;
}

struct node* Delete(struct node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {  // key is in the left sub tree.
        root->left = Delete(root->left, key);
    } else if (key > root->key) { // key is in the right sub tree.
        root->right = Delete(root->right, key);
    } else {  // key is equal the key of the current node.
        // case 1: no children
        if (root->left == NULL && root->right == NULL) {
            delete(root); // wipe out the memory, in C, use free function
            root = NULL;
        }
        // case 2: one child (right)
        else if (root->left == NULL) {
            struct node *temp = root; // save current node as a backup
            root = root->right;
            delete temp;
        }
        // case 3: one child (left)
        else if (root->right == NULL) {
            struct node *temp = root; // save current node as a backup
            root = root->left;
            delete temp;
        }
        // case 4: two children
        else {
            struct node *temp = FindMin(root->right); // find minimal value of right sub tree
            root->key = temp->key; // duplicate the node
            root->right = Delete(root->right, temp->key); // delete the duplicate node
        }
    }
    return root; // parent node can update reference
}


void createListofLeavesHelper(struct node* root, vector<int> &list) {
    
    if(root) {
        if ((root->left == NULL) && (root->right == NULL)){
            list.emplace_back(root->key);
        }
        createListofLeavesHelper(root->left, list);
        createListofLeavesHelper(root->right,list);
    }
}

void createListofLeaves(struct node *root) {
    vector<int> leaveList;
    createListofLeavesHelper(root, leaveList);
    
    for(auto c:leaveList){
        cout<<c<<" ";
    }
    cout<<endl;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
     50
     /     \
     30      70
     /  \    /  \
     20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    //insert(root, 60);
    insert(root, 80);
    
    // print inoder traversal of the BST
    MaxNodeAtLevel(root);
    //Delete(root,70);
    //PreOrderTraversal(root);
    //createListofLeaves(root);
    inorder(root);
    cout<<endl;
    //levelOrderTraversal(root);
    //int level = MaxNodeAtLevel(root);
    //cout<<"Level "<<level<<" has the maximum number of nodes"<<endl;
    //printf("Height of BST is %d\n", height(root));
    //buildNodeLevelList(root);
    //InOrderTraversal(root);
    //cout<<"Iterative Preorder Traversal - ";
    //PreOrderTraversal(root);
    //cout<<endl<<"Recursive Preorder Traversal - ";
    //preorder(root);
    //cout<<"4th Node in Inorder Traversal is - ";
    //NthInorder(root, 4);
    
#if 0
    struct node* node1 = newNode(20);
    struct node* node2 = newNode(40);
    struct node* lca = findLCA(root, node1, node2);
    cout<<"LCA of 60 and 80 is "<<lca->key<<endl;
    cout<<endl;
#endif
    return 0;
}
