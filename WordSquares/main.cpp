//
//  main.cpp
//  WordSquares
//
//  Created by bsarvan on 03/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Given a set of words (without duplicates), find all word squares you can build from them.
 A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
 For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
 b a l l
 a r e a
 l e a d
 l a d y
 Note:
 There are at least 1 and at most 1000 words.
 All words will have the exact same length.
 Word length is at least 1 and at most 5.
 Each word contains only lowercase English alphabet a-z.
 
 Example 1:
 Input:
 ["area","lead","wall","lady","ball"]

 Output:
 [
   [ "wall",
     "area",
     "lead",
     "lady"
   ],
   [ "ball",
     "area",
     "lead",
     "lady"
   ]
 ]

 Explanation:
 The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
 Example 2:
 Input:
 ["abat","baba","atan","atal"]

 Output:
 [
   [ "baba",
     "abat",
     "baba",
     "atan"
   ],
   [ "baba",
     "abat",
     "baba",
     "atal"
   ]
 ]

 Explanation:
 The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    bool isWord;
    struct TrieNode *children[26];
    
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};



void InsertString(TrieNode *root, string S) {
    TrieNode *curr = root;
    
    for (int i = 0; i < S.length(); i++) {
        int index = S[i] - 'a';
        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    
    curr->isWord = true;
}

TrieNode * SearchPrefix(TrieNode *root, string prefix) {
    TrieNode *curr = root;
    
    for (int i = 0; i < prefix.size(); i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == nullptr) {
            return nullptr;
        }
        
        curr = curr->children[i];
    }
    
    return curr;
}

void GetAllChildren(TrieNode *node, string word, vector<string> &words) {
    if (node->isWord) {
        words.emplace_back(word);
        return;
    }
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            GetAllChildren(node->children[i], word + char('a' + i) , words);
        }
    }
}


string GetPrefix(vector<string> square, int index) {
    string result;
    
    for (int i = 0; i < square.size(); i++) {
        result += square[i][index];
    }
    return result;
}


TrieNode* BuildTrie(vector<string> words) {
    TrieNode *root = new TrieNode();
    
    TrieNode *curr = root;
    for (auto word : words) {
        InsertString(curr, word);
    }
    
    return root;
}

void WordSquaresHelper(TrieNode *root, size_t len, vector<string> square, vector<vector<string>> &squares) {
    if (square.size() == len) {
        squares.emplace_back(square);
        return;
    }
    int N = (int)square.size();
    string prefix = GetPrefix(square, N);
    TrieNode *node = SearchPrefix(root, prefix);
    
    if (node == nullptr) {
        return;
    }
    
    vector<string> words;
    GetAllChildren(node, prefix, words);
    
    for (auto word : words) {
        square.emplace_back(word);
        WordSquaresHelper(root, len, square, squares);
        square.pop_back();
    }
    
    return;
}


vector<vector<string>> WordSquares(vector<string> words){
    TrieNode *root = BuildTrie(words);
    
    vector<vector<string>> squares;
    
    for (auto word : words) {
        vector<string> square;
        square.emplace_back(word);
        WordSquaresHelper(root, words.size(), square, squares);
    }
    
    return squares;
    
}


int main(int argc, const char * argv[]) {
    
    vector<string> words = {"area","lead","wall","lady","ball"};
    
    vector<vector<string>> squares = WordSquares(words);
    
    for (auto square : squares) {
        for ( auto word : square ) {
            cout<<word<<endl;
        }
        cout<<"================"<<endl;
    }
    
    return 0;
}
