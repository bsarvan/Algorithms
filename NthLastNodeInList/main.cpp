//
//  main.cpp
//  NthLastNodeInList
//
//  Created by Bharat Sarvan on 09/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


struct node {
    int val;
    struct node *next;
    node(int key) {
        val = key;
        next = NULL;
    }
};




node* NthLastNode( node *head, int k, int &i) {
    if (head == NULL) {
        return NULL;
    }
    
    node *tmp_node = NthLastNode(head->next, k, i);
    i = i + 1;
    if (i == k) {
        cout<<"Returning the "<<k<<"th Node - "<<head->val<<endl;
        return head;
    }
    return tmp_node;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the Nth Last Node in the list"<<endl;
    
    node *head = new node(1);
    node *curr = head;
    
    for (int i = 2; i <= 10; i++) {
        curr->next = new node(i);
        curr = curr->next;
    }
    
    curr = head;

    while(curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    
    cout<<endl;
    
    int i = 0;
    node *KthNode = NthLastNode(head, 2, i);
    
    cout<<"Kth Node from end of the list is "<<KthNode->val<<endl;
    
    return 0;
}
