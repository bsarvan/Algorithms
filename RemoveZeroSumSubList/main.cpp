//
//  main.cpp
//  RemoveZeroSumSubList
//
//  Created by Bharat Sarvan on 08/02/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//


/*
 LeetCode
 
 1171. Remove Zero Sum Consecutive Nodes from Linked List
 Medium

 762

 48

 Add to List

 Share
 Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

 After doing so, return the head of the final linked list.  You may return any such answer.

  

 (Note that in the examples below, all sequences are serializations of ListNode objects.)

 Example 1:

 Input: head = [1,2,-3,3,1]
 Output: [3,1]
 Note: The answer [1,2,1] would also be accepted.
 Example 2:

 Input: head = [1,2,3,-3,4]
 Output: [1,2,4]
 Example 3:

 Input: head = [1,2,3,-3,-2]
 Output: [1]
  

 Constraints:

 The given linked list will contain between 1 and 1000 nodes.
 Each node in the linked list has -1000 <= node.val <= 1000.
 
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *curr = head;
        ListNode *dummy = new ListNode (-1);
        
        dummy->next = head;
        ListNode *pre = dummy;
        
        while(curr) {
            int sum = 0;
            ListNode *tmp = curr;
            sum += tmp->val;
            tmp = tmp->next;
            while(tmp and sum != 0) {
                sum += tmp->val;
                tmp = tmp->next;
            }
            
            if (sum == 0) {
                pre->next = tmp;
                curr = tmp;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};

void Append(ListNode** tail, ListNode** node) {
    (*tail)->next = *node;
    *tail = *node;
    (*node) = (*node)->next;
}

void PrintList(ListNode *head) {
    ListNode *curr = head;
    while(curr) {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    vector<int> input = {1,2,3,-3,5};
    
    // Build the List
    ListNode *head = nullptr;
    
    ListNode *head_iter = nullptr;
    for (auto a : input) {
        if (head == nullptr) {
            head = new ListNode(a);
            head_iter = head;
        } else {
            ListNode *n = new ListNode(a);
            Append(&head_iter, &n);
        }
    }
    
    PrintList(head);
    
    Solution sol;
    
    ListNode *newList = sol.removeZeroSumSublists(head);
    
    PrintList(newList);
    return 0;
}
