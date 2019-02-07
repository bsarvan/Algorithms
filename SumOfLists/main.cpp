//
//  main.cpp
//  SumOfLists
//
//  Created by bsarvan on 14/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Node_ {
    int d;
    struct Node_ *next;
} Node;


void addNode(Node **head, int num) {
    
    Node *node = new Node();
    node->d = num;
    node->next = *head;
    *head = node;
}

void printList(Node *head){
    Node *curr = head;
    
    while(curr) {
        cout<<curr->d<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

Node *addLists(Node *L1, Node *L2, int carry) {
    if ((L1 == NULL) && (L2 == NULL) && (carry == 0)) {
        return NULL;
    }
    
    Node *result = new Node();
    int value = carry;
    
    if (L1) {
        value += L1->d;
    }
    
    if (L2) {
        value += L2->d;
    }
    
    int secondDigit = value % 10;
    result->d = secondDigit;
    
    if ((L1 != NULL) || (L2 != NULL)) {
        Node *node = addLists(L1 == NULL? NULL:L1->next, L2 == NULL? NULL:L2->next,value >= 10? 1:0);
        result->next = node;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to add two lists"<<endl;
    Node *list1 = NULL;
    Node *list2 = NULL;
    
    addNode(&list1, 6);
    addNode(&list1, 1);
    addNode(&list1, 7);
    
    printList(list1);
    
    addNode(&list2, 2);
    addNode(&list2, 9);
    addNode(&list2, 5);
    cout<<"+"<<endl;
    printList(list2);
    cout<<"="<<endl;
    Node *result = addLists(list1, list2, 0);
    
    printList(result);
    
    return 0;
}
