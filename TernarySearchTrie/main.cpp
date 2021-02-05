//
//  main.cpp
//  TernarySearchTrie
//
//  Created by Bharat Sarvan on 02/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    bool isLastChar;
    struct Node *left, *equal, *right;
    
    Node (char d) {
        data = d;
        left = equal = right = nullptr;
    }
};

Node *root = nullptr;

Node* add(Node *curr, string word, int wordIndex) {
    if (curr == nullptr) {
        curr = new Node(word[wordIndex]);
    }
    
    if (word[wordIndex] < curr->data) {
        curr->left = add(curr->left, word, wordIndex);
    } else if (word[wordIndex] > curr->data) {
        curr->right = add(curr->right, word, wordIndex);
    } else {
        if (wordIndex < word.size() - 1) {
            curr->equal = add(curr->equal, word, wordIndex + 1);
        } else {
            curr->isLastChar = true;
        }
    }
    
    return curr;
}

void add(string word) {
    root = add(root, word, 0);
}

bool find(Node *curr, string word, int wordIndex) {
    if (curr == nullptr) {
        return false;
    }
    
    if (word[wordIndex] < curr->data) {
        return find(curr->left, word, wordIndex);
    } else if (word[wordIndex] > curr->data) {
        return find(curr->right, word, wordIndex);
    } else {
        if (wordIndex == word.size() - 1) {
            return curr->isLastChar;
        } else {
            return find(curr->equal, word, wordIndex + 1);
        }
    }
    return false;
}


void  find(string word) {
    bool ret = find(root, word, 0);
    cout<<word<<" :: ";
    if (ret) {
        cout<<"Found"<<endl;
    } else {
        cout<<"Not Found"<<endl;
    }
    
    return;
}


int main(int argc, const char * argv[]) {

    add("banana");
    add("apple");
    add("mango");
    
    cout<<"Search Results - "<<endl;
    
    find("apple");
    find("banana");
    find("cherry");
    
    return 0;
}
