//
//  main.cpp
//  XORLinkedList
//
//  Created by bsarvan on 05/06/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


struct Node {
    int val;
    struct Node *both;
    
    Node(int v) {
        val = v;
        both = NULL;
    }
};

typedef struct Node* pNode;

pNode NextNode(pNode p1, pNode p2) {
    return (pNode) ((long int)p1 ^ (long int)p2->both);
}

pNode XoR(pNode p1, pNode p2) {
    return (pNode)((long int)p1 ^ (long int)p2);
}

void insertNode(struct Node **head, int v) {
    pNode m = new Node(v);
    
    if (*head == NULL) {
        *head = m;
        return;
    }
    
    auto curr = *head;
    pNode prev = NULL;
    
    while(curr) {
        pNode next  = NextNode(prev,curr);
        prev  = curr;
        curr = next;
    }
    
    m->both = XoR(prev,NULL);
    prev->both = XoR(m, XoR(prev->both,NULL));
    
}

void deleteNode(pNode *head, int val)
{
    pNode prev = NULL;
    pNode curr = *head;
    pNode next = NULL;
    pNode pprev = NULL;
    
    if ((*head)->val == val) {
        next = XoR((*head)->both, NULL);
        next->both = XoR(NULL, XoR(*head, next->both));
        *head = next;
        return;
    }
    
    while (curr) {
        next = NextNode(prev, curr);
        if (curr->val == val) {
            cout<<"Value is "<<curr->val<<endl;
            pprev = XoR(prev->both, curr);
            prev->both= XoR(pprev, next);
            break;
        }
        prev = curr;
        curr = next;
    }
    
    return;
}

void printList(pNode head) {
    pNode curr = head;
    pNode next;
    pNode prev = NULL;
    
    while(curr) {
        next = NextNode(prev, curr);
        cout<<curr->val<<" ";
        prev = curr;
        curr = next;
    }
    cout<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    cout<<"Sample program for XOR Linked List"<<endl;
    
    struct Node *head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    
    printList(head);
    
    deleteNode(&head, 3);
    
    printList(head);
    
    return 0;
}
