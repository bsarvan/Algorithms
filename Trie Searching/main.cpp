//
//  main.cpp
//  Trie Searching
//
//  Created by bsarvan on 18/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    
    pNode->isEndOfWord = false;
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    
    cout<<"String to insert - "<<key<<endl;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        cout<<"TrieNode - "<<pCrawl<<", Index - "<<index<<endl;
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
        pCrawl = pCrawl->children[index];
    }
    
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        
        pCrawl = pCrawl->children[index];
    }
    
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}


int main() {
    
    cout<<"Test Program to validate Trie Data Structure Operations"<<endl;
    
    struct TrieNode *root = getNode();
    
    insert(root, "the");
    insert(root, "thing");
    
    bool result = search(root, "thing");
    if(result)
        cout<<"Found the key"<<endl;
    
    return 0;

}

#if 0
// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
        "answer", "any", "by",
        "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    
    struct TrieNode *root = getNode();
    
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
    cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
    cout << "No\n";
    return 0;
}
#endif

