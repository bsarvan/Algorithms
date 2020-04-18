//
//  main.cpp
//  RankFromStream
//
//  Created by bsarvan on 19/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class RankNode {
public:
    int left_size = 0;
    RankNode *left,*right;
    int key;
    RankNode(int val):key(val), left(nullptr), right(nullptr){}
    
    void insert(int val) {
        if (val <= key) {
            if (left != nullptr) {
                left->insert(val);
            } else {
                left = new RankNode(val);
            }
            cout<<"Node val - "<<val<<", left_size - "<<left_size<<endl;
            left_size++;
            
        } else {
            if (right != nullptr) {
                right->insert(val);
            } else {
                right = new RankNode(val);
            }
        }
    }
    
    int getRank(int d) {
        cout<<"Getting Rank for  - "<<d<<endl;
        
        if (d == key)
            return left_size;
        else if (d < key) {
            if (left == nullptr) {
                return -1;
            } else {
                left->getRank(d);
            }
        } else {
            int right_rank = right == nullptr ? -1: right->getRank(d);
            if (right_rank == -1) {
                return -1;
            } else {
                return (left_size + 1 + right_rank);
            }
        }
        return -1;
    }
};


RankNode *root = NULL;

void track(int val) {
    if (root == nullptr) {
        root = new RankNode(val);
    } else {
        root->insert(val);
    }
}

int getRankOfNumber(int val) {
    return root->getRank(val);
}

void inorder(RankNode *root) {
    if (root) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> N = {50,30,20,40,70,60,80};
    cout<<"Program to get rank of a number in a stream of numbers"<<endl;
    for (auto c:N) {
        track(c);
    }
    
    inorder(root);
    cout<<endl;
    
    int result = getRankOfNumber(50);
    cout<<"Rank of Number 50 - "<<result<<endl;
    
    return 0;
}
