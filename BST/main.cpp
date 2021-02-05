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
#include <string>
#include <unordered_set>

using namespace std;

struct node
{
    int key;
    struct node *left, *right;
    node(int x) : key(x), left(NULL), right(NULL) {}
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
        return 0;
    
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
    if (node == NULL) {
        return newNode(key);
    }
    
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

void printLevelOrder(struct node *root){
    queue<struct node *> q;
    q.push(root);
    
    while(!q.empty()) {
        int  NodeCount = q.size();
        
        while(NodeCount){
            struct node *n = q.front();
            cout<<n->key<<" ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
            q.pop();
            NodeCount--;
        }
        cout<<endl;
    }
}


void createLinkedList(struct node *root, unordered_map<int,list<struct node *>> &lists, int level) {
    if (root == NULL){
        return;
    }
    list<struct node*> nodeList;
    unordered_map<int, list<struct node *>>::iterator iter = lists.find(level);
    //if(iter == lists.end()) {
    if (lists.size() == level) {
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
    
    /* Print the list of nodes at each level */
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
    int inorder = 0;
    
    while(!q.empty() || curr) {
        if(curr) {
            q.push(curr);
            curr = curr->left;
        } else {
            curr = q.top();
            q.pop();
            cout<<inorder<<" "<<curr->key<<endl;
            inorder = curr->key;
            curr = curr->right;
        }
    }
}


bool isValidBST(struct node *root) {
    stack<struct node *> S;
    struct node *curr = root;
    int prevNode = INT_MIN;
    
    while(!S.empty() || curr) {
        if (curr) {
            S.push(curr);
            curr = curr->left;
        } else {
            curr = S.top();
            S.pop();
            if (prevNode > curr->key) {
                return false;
            }
            prevNode = curr->key;
            curr = curr->right;
        }
    }
    return true;
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

/* Rebuild a BST from a PreOrder Sequence of numbers */
struct node* RebuildBST(vector<int> A, int start, int end) {
    if (start >= end) {
        return nullptr;
    }
    
    cout<<"Root - "<<A[start]<<endl;
    
    int transition = start + 1;
    
    cout<<"Transtion Point -";
    while((transition < end) &&
          A[transition] < A[start]) {
        ++transition;
        cout<<" "<<transition;
    }
    cout<<endl;
    cout<<"Left Subtree Root - "<<A[start+1]<<", Right Subtree Root - "<<A[transition]<<endl;
    
    struct node *N = new node(A[start]);
    N->left = RebuildBST(A, start+1, transition);
    N->right = RebuildBST(A, transition, end);
    
    return N;
 }


struct node* RebuildBSTFromRange(vector<int> A, int low, int high, size_t &root_index) {
    
    if (root_index == A.size()) {
        return nullptr;
    }
    
    int root = A[root_index];
    
    if ( root < low || root > high) {
        return nullptr;
    }
    
    root_index++;
    
    auto left = RebuildBSTFromRange(A, low, root, root_index);
    auto right = RebuildBSTFromRange(A, root, high, root_index);
    struct node *N = new node(root);
    N->left = left;
    N->right = right;
    return (N);
}


#if 0
int longestUnivaluePath(node* root) {
    int lup = 0;
    if (root) dfs(root, lup);
    return lup;
}

private:
int dfs(node* N, int& lup) {
    int l = N->left ? dfs(N->left, lup) : 0;
    int r = N->right ? dfs(N->right, lup) : 0;
    int resl = N->left && N->left->val == N->val ? l + 1 : 0;
    int resr = N->right && N->right->val == N->val ? r + 1 : 0;
    lup = max(lup, resl + resr);
    return max(resl, resr);
}
#endif


void postOrder(node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->key<<" ";
    }
    return;
}


void postOrderIterative(node *root) {
    stack<node *> S;
    S.emplace(root);
    
    while(!S.empty()) {
        auto curr = S.top();
        S.pop();
        if(curr) {
            cout<<curr->key<<" ";
            S.emplace(curr->right);
            S.emplace(curr->left);
        }
    }
    cout<<endl;
}

string getNextElem(string s, size_t &offset) {
    size_t end = s.find(',', offset);
    if (end == string::npos) {
        end = s.length();
    }
    string sValue = s.substr(offset,end - offset);
    offset = end + 1;
    return (sValue);
}

void serialize(struct node *root, string &s) {
    if (root == NULL) {
        s = s + '#';
        s += ',';
        return;
    }
    
    s += to_string(root->key);
    s += ',';
    serialize(root->left, s);
    serialize(root->right, s);
}


void deserialize(struct node *&root, string s, size_t &offset) {
    string sVal = getNextElem(s, offset);
    if (s.empty() || sVal == "#") {
        return;
    }
    root = new node(stoi(sVal));
    deserialize(root->left, s, offset);
    deserialize(root->right, s, offset);
}


void buildTreeFromPreorderSeq(struct node *&root, vector<int> V, size_t &offset) {
    int key = V[++];
    
    if (key == -offset1) {
        return;
    }
    root = new node(key);
    buildTreeFromPreorderSeq(root->left, V, offset);
    buildTreeFromPreorderSeq(root->right, V, offset);
    return;
}

void inorderFindPair(struct node *root, unordered_set<int> &S, int K) {
    if (root != NULL) {
        inorderFindPair(root->left, S, K);
        
        if (S.find(K - root->key) != S.end()) {
            cout<<root->key<<" , "<<K-root->key<<endl;
            return;
        }
        
        S.insert(root->key);
        
        inorderFindPair(root->right, S, K);
    }
}


int findLeftHeight(struct node *root) {
    int height = 0;
    struct node* tmp = root;
    
    while(tmp){
        height++;
        tmp = tmp->left;
    }
    return (height-1);
}

int findRightHeight(struct node *root) {
    int height = 0;
    struct node* tmp = root;
    
    while(tmp){
        height++;
        tmp = tmp->right;
    }
    return (height-1);
}

/*
 Given a complete binary tree, count the number of nodes in faster than O(n) time.
 Recall that a complete binary tree has every level filled except the last,
 and the nodes in the last level are filled starting from the left.
 */
int countNodes(struct node* root) {

    if (root == NULL) {
        return 0;
    }
    
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
    
    if (lh == rh) {
        return ((2 << lh) - 1);
    } else {
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
    
}


int countNodes_v2(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    
    return (1 + countNodes_v2(root->left) + countNodes_v2(root->right));
}


struct node * cloneTree(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct node *cloned = new node(root->key);
    cloned->left = cloneTree(root->left);
    cloned->right = cloneTree(root->right);
    
    return cloned;
}


//Compute the exterior of binary tree

bool isLeaf(struct node* root) {
    if (root->left == nullptr && root->right == nullptr)
        return true;
    else
        return false;
}

void LeftBoundaryAndLeaves(struct node *root, bool boundary, vector<int> &exterior) {
    if (root) {
        if (boundary || isLeaf(root)) {
            exterior.emplace_back(root->key);
        }
        
        LeftBoundaryAndLeaves(root->left, boundary, exterior);
        LeftBoundaryAndLeaves(root->right, boundary && root->left == nullptr, exterior);
    }
}

void RightBoundaryAndLeaves(struct node *root, bool boundary, vector<int> &exterior) {
    if (root) {
        RightBoundaryAndLeaves(root->left, boundary && root->right == nullptr, exterior);
        RightBoundaryAndLeaves(root->right, boundary, exterior);
        
        if (boundary || isLeaf(root)) {
            exterior.emplace_back(root->key);
        }
    }
}


void BuildExteriorOfBinaryTree(struct node* root) {
    vector<int> exterior;
    if (root) {
        exterior.emplace_back(root->key);
        LeftBoundaryAndLeaves(root->left, true, exterior);
        RightBoundaryAndLeaves(root->right, true, exterior);
    }
    
    for(auto e:exterior)
        cout<<e<<" ";
    
    cout<<endl;
    
}


struct node * BuildBSTFromPostOrder(vector<int> seq, int start, int end) {
    
    if (start < end){
        return nullptr;
    }
    
    int transition = start - 1;
    while(transition >= 0 && seq[transition] > seq[start]) {
        transition--;
    }
  
    
    struct node *root = new node(seq[start]);
    root->right = BuildBSTFromPostOrder(seq, start - 1, transition + 1);
    root->left = BuildBSTFromPostOrder(seq, transition, end);
    
    return root;
}


struct node *BuildBSTFromPostOrderRange(vector<int> A, int min, int max, size_t &root_index) {
    if (root_index > 0) {
        return nullptr;
    }
    
    int val = A[root_index];
    
    if (val < min || val > max) {
        return nullptr;
    }
    root_index--;
    
    struct node* root = new node(val);
    root->right = BuildBSTFromPostOrderRange(A, val, max, root_index);
    root->left = BuildBSTFromPostOrderRange(A, min, val, root_index);
    
    return root;
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
    insert(root, 60);
    insert(root, 80);
    
    postOrder(root);
    cout<<endl;
    
    /* Build BST from a post order sequence*/
    vector<int> postorder = {20,40,30,60,80,70,50};
    struct node* bst_root = BuildBSTFromPostOrder(postorder,postorder.size() - 1, 0);
    size_t root_index = postorder.size() - 1;
    struct node* bst_from_range = BuildBSTFromPostOrderRange(postorder, INT_MIN, INT_MAX, root_index);
    postOrder(bst_root);
    postOrder(bst_from_range);
    cout<<endl;
    
    
    vector<int> PreOrder = {50, 30, 20, 40, 70, 60, 80};
    
    cout<<"Build BST from PreOrder Traversed Info"<<endl;
    root_index = 0;
    struct node *N = RebuildBSTFromRange(PreOrder, INT_MIN, INT_MAX, root_index);
    cout<<endl;
    inorder(N);
    cout<<endl;
    
//    BuildExteriorOfBinaryTree(root);
//    buildNodeLevelList(root);
    
//    unordered_set<int> S;
//    inorderFindPair(root, S, 100);
       
#if 0
    /* Build BST from PreOrder Sequence with delimiters */
//    vector<int> preOrder = {50,30,20,-1,-1,40,-1,-1,70,60,-1,-1,80,-1,-1};
//    struct node *BinaryTree;
//    size_t j = 0;
//    buildTreeFromPreorderSeq(BinaryTree, preOrder, j);
//    inorder(BinaryTree);
    
    /* Compute height and number of nodes in a BST */
//    printf("Height of BST is %d\n", height(root));
//    cout<<"Number of Nodes in Tree - "<<countNodes(root)<<endl;
//    cout<<"Number of Nodes in Tree - "<<countNodes_v2(root)<<endl;
//
    /* Serializing and Deserializing the BST Start*/
//    string S;
//    serialize(root, S);
//    //postOrder(root);
//    cout<<S<<endl;
//
//    struct node *N;
//    size_t i = 0;
//    deserialize(N, S, i );
//
//    inorder(N);
//    cout<<endl;
    /* Serializing and Deserializing the BST Start*/
    
    vector<int> preOrder = {50,30,20,-1,-1,40,-1,-1,70,60,-1,-1,80,-1,-1};
    struct node *BinaryTree;
    size_t j = 0;
    buildTreeFromPreorderSeq(BinaryTree, preOrder, j);
    inorder(BinaryTree);

    //postOrderIterative(root);
    
    vector<int> PreOrder = {50, 30, 20, 40, 70, 60, 80};
    
    // print inoder traversal of the BST
    //MaxNodeAtLevel(root);
    //Delete(root,70);
    //PreOrderTraversal(root);
    //createListofLeaves(root);

    inorder(root);
    
    struct node *ClonedRoot = cloneTree(root);
    
    cout<<endl<<"Inorder Traversal of cloned tree"<<endl;
    inorder(ClonedRoot);
    
    //printLevelOrder(root);
    cout<<endl;

    cout<<"Build BST from PreOrder Traversed Info"<<endl;
    
    struct node *N = RebuildBST(PreOrder, 0, PreOrder.size());

    cout<<endl;
    inorder(N);
    cout<<endl;

    
    //levelOrderTraversal(root);
    cout<<endl;
    //int level = MaxNodeAtLevel(root);
    //cout<<"Level "<<level<<" has the maximum number of nodes"<<endl;
    //buildNodeLevelList(root);
    //InOrderTraversal(root);
    //cout<<"Iterative Preorder Traversal - ";
    //PreOrderTraversal(root);
    //cout<<endl<<"Recursive Preorder Traversal - ";
    //preorder(root);
    //cout<<"4th Node in Inorder Traversal is - ";
    //NthInorder(root, 4);
#endif
    
#if 0
    struct node* node1 = newNode(20);
    struct node* node2 = newNode(40);
    struct node* lca = findLCA(root, node1, node2);
    cout<<"LCA of 60 and 80 is "<<lca->key<<endl;
    cout<<endl;
#endif
    return 0;
}
