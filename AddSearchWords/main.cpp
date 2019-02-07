//
//  main.cpp
//  AddSearchWords
//
//  Created by bsarvan on 25/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


class TrieNode {
public:
    bool isKey;
    TrieNode *children[26];
    TrieNode():isKey(false) {
        memset(children,NULL, sizeof(TrieNode)*26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!(run -> children[c - 'a']))
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isKey = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }
    
private:
    TrieNode* root;
    
    bool query_backup(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run -> isKey;
    }
    
    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (!run -> children[word[i] - 'a'])
                return false;
            
            run = run -> children[word[i] - 'a'];
        }
        return run && run->isKey;
    }
};


int main() {
    cout<<"Program to add and search words"<<endl;
    
    WordDictionary dict;
    dict.addWord("bharat");
    dict.addWord("sarvan");
    bool found = dict.search("bharat");
    cout<<"Search result is - "<<(found == true? "TRUE":"FALSE")<<endl;
    return 0;
}
