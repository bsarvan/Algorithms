//
//  main.cpp
//  SerializeBinaryTree
//
//  Created by Bharat Sarvan on 27/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
    
    Node (int val):key(val), left(nullptr), right(nullptr) {}
};

void printInOrder(Node *root) {
    if (root) {
        printInOrder(root->left);
        cout<<root->key<<" ";
        printInOrder(root->right);
    }
}


//string serialize(Node *root) {
//    if (root == nullptr) {
//        return ",null";
//    }
//    string str;
//    str = to_string(root->key);
//    if (root->left) {
//        str += ",";
//    }
//    str += serialize(root->left);
//
//    if (root->right) {
//        str += ",";
//    }
//    str += serialize(root->right);
//
//    return str;
//}


string serialize(Node *root) {
    if (root == nullptr) {
        return "null";
    }
    string str;
    str = to_string(root->key);
    
    str += ",";
    str += serialize(root->left);
    
    str += ",";
    str += serialize(root->right);
    
    return str;
}

string GetNextVal(string data, size_t &offset) {
    auto end = data.find(',', offset);
    if (end == string::npos) {
        end = data.length();
    }
    
    string sval = data.substr(offset, end - offset);
    offset = end + 1;
    return sval;
}

void deserializeHelper(Node *&root, string data, size_t &offset) {
    
    string sval = GetNextVal(data, offset);
    
    if (data.empty() || sval == "null") {
        return;
    }
    
    root = new Node(stoi(sval));
    deserializeHelper(root->left, data, offset);
    deserializeHelper(root->right, data, offset);
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    Node *curr;
    size_t offset = 0;
    
    deserializeHelper(curr, data, offset);
    return curr;
}

int main(int argc, const char * argv[]) {
    Node *root = new Node(5);
    root->left  = new Node(3);
    root->right = new Node(7);
    
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    
    printInOrder(root);
    cout<<endl;
    
    string result = serialize(root);
    cout<<result<<endl;
    Node *newRoot = deserialize(result);
    
    printInOrder(newRoot);
    cout<<endl;
    return 0;
}
