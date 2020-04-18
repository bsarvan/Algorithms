//
//  main.cpp
//  ReorderList
//
//  Created by bsarvan on 21/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    
    ListNode(int v):val(v), next(NULL) {}
};



void appendNode (ListNode *head, int key) {
    ListNode *curr = head;
    ListNode *node = new ListNode(key);
    
    while(curr->next) {
        curr = curr->next;
    }
    
    curr->next = node;
    return;
}

void printList(ListNode *head) {
    ListNode *curr = head;
    cout<<"List - ";
    while(curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


void reorderList(ListNode *head) {
    stack<ListNode *> S;
    ListNode *slow = head;
    ListNode *fast  =head;
    
    while(fast && fast->next) {
        cout<<"Pushing - "<<slow->val<<endl;
        S.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    
    ListNode *node2 = fast == NULL? slow : slow->next;
    ListNode *tail = fast == NULL? NULL:slow;
    
    
    
    if (tail)
        tail->next = NULL;
    
//    cout<<"Tail - "<<tail->val<<endl;
    
    while(!S.empty()) {
        ListNode *node1 = S.top();
        S.pop();
        cout<<"Stack - "<<node1->val<<", node2 - "<<node2->val<<endl;
        
        node1->next = node2;
        
        ListNode *tmp = node2;
        node2 = node2->next;
        tmp->next = tail;
        
        tail = node1;
    }
}

int main(int argc, const char * argv[]) {
    
    ListNode *head = new ListNode(1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);
    appendNode(head, 7);
    appendNode(head, 8);
    
    printList(head);
    
    reorderList(head);
    
    printList(head);
    return 0;
}


/*
1 2 3 4 5 6 7 8           Fast here is NULL, Slow here is 4

1 8 2 7 3 6 4 5
                 Node 1 and Node 2.
                 Node 1 is extracted from the stack
                 Node 2 is the half of the list
                
                Action to be performed is
                Node 1 -> next  = Node 2;
                Node 2  = Fast == NULL ? slow : slow->next;

                Node 1 is extracted from Stack
                Node 2 from the half of the list till the end
                Tail in the loop to be updated to Node 2
                
                while(!S.empty()) {
                    


1 2 3 4 5 6 7             Fast here is not NULL, Slow here is 4

1 7 2 6 3 5 4
*/
