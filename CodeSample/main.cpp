//
//  main.cpp
//  CodeSample
//
//  Created by bsarvan on 11/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TrieNode {
    string key;
    TrieNode *children[26];
    
    TrieNode() {
        for(int i=0;i<26;i++) {
            children[i] = NULL;
        }
    }
};


void insert(TrieNode* root, string str) {
    TrieNode *head = root;
    
    for (int i = 0; i < str.size(); i++) {
        int index = str[i] - 'a';
        if (head->children[index] == NULL) {
            head->children[index] = new TrieNode();
        }
        head = head->children[index];
    }
    head->key = str;
    return;
}


void preOrder(TrieNode *root) {
    if (root == NULL) {
        return;
    }
    
    for (int i = 0; i < 26; i++){
        if (root->children[i] != NULL) {
            if (root->children[i]->key.size() > 0) {
                cout<<root->children[i]->key<<endl;
            }
        }
        preOrder(root->children[i]);
    }
}

int main(int argc, const char * argv[]) {
    TrieNode *root = new TrieNode();
    
    vector<string> names = {"bharat", "tavish", "rupal"};
    
    for (auto n:names) {
        insert(root, n);
    }
    
    preOrder(root);
    
    std::cout << "Hello, World!\n";
    return 0;
}
