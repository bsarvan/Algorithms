//
//  main.cpp
//  LexographicSortingOfStrings
//
//  Created by bsarvan on 24/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define character size
// Trie supports lowercase English characters (a - z)
#define CHAR_SIZE 26

// A Trie node
struct Trie
{
    string key;    // set when node is a leaf node
    Trie* character[CHAR_SIZE];
    
    // Constructor
    Trie()
    {
        for (int i = 0; i < CHAR_SIZE; i++) {
            character[i] = nullptr;
        }
    }
};

// Iterative function to insert a string in Trie.
void insert(Trie* &head, string const &str)
{
    // start from root node
    Trie* curr = head;
    
    for (char ch: str)
    {
        // create a new node if path doesn't exists
        if (curr->character[ch - 'a'] == nullptr) {
            curr->character[ch - 'a'] = new Trie();
        }
        
        // go to next node
        curr = curr->character[ch - 'a'];
    }
    
    // store key in leaf node
    curr->key = str;
}


// Returns true if key presents in trie, else
// false
Trie* search(struct Trie *root, string key)
{
    struct Trie *pCrawl = root;
    
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->character[index])
            return nullptr;
        
        pCrawl = pCrawl->character[index];
    }
    return pCrawl;
}

void getChildren(Trie *node, string prefix, vector<string> &childrens) {
    if (node->key.length() != 0) {
        childrens.emplace_back(node->key);
        return;
    }
    
    for (int i = 0; i < 26; i++ ) {
        if (node->character[i]) {
            getChildren(node->character[i], prefix + char('a' + i), childrens);
        }
    }
    return;
}

void getChildren_v2(Trie *node, vector<string> &childrens) {
    if (node->key.length() != 0) {
        childrens.emplace_back(node->key);
        return;
    }
    
    for (int i = 0; i < 26; i++ ) {
        if (node->character[i]) {
            getChildren_v2(node->character[i], childrens);
        }
    }
    return;
}


// Function to perform pre-order traversal of given Trie
void preorder(Trie* const curr)
{
    // return false if Trie is empty
    if (curr == nullptr) {
        cout<<"Trie is Empty"<<endl;
        return;
    }
    
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (curr->character[i] != nullptr)
        {
            // if leaf node, print key
            if (curr->character[i]->key.size() > 0){
                cout << curr->character[i]->key << '\n';
            }
            
            preorder(curr->character[i]);
        }
    }
    return;
}

// main function
int main()
{
    Trie* head = new Trie();
    
    // given set of keys
    string dict[] =
    {
        "lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
        "be", "accomplished", "with", "a", "simple", "trie", "based",
        "algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
        "output", "all", "keys", "in", "the", "trie", "by", "means", "of",
        "preorder", "traversal", "which", "results", "in", "output", "that",
        "is", "in", "lexicographically", "increasing", "order", "preorder",
        "traversal", "is", "a", "kind", "of", "depth", "first", "traversal", "sorted"
    };
    
    // insert all keys of dictionary into trie
    for (string word: dict) {
        insert(head, word);
    }
    
    // print keys in lexicographic order
    preorder(head);
    
//    Trie* node = search(head, "sort");
//    vector<string> strs;
//    getChildren_v2(node, strs);
//    for (auto s:strs)
//        cout<<s<<endl;
//

//
//    vector<string> strs;
//    getChildren(node, "sort", strs);
//
//    for (auto s:strs)
//        cout<<s<<endl;
//
    return 0;
}
