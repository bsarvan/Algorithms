//
//  main.cpp
//  LinkedListReverseOperation
//
//  Created by Bharat Sarvan on 06/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

// Add any helper functions you may need here


Node* reverse(Node *head) {
  // Write your code here
    Node *curr = head;
    Node* dummy = new Node(0);
    Node* pre = nullptr;
    
    dummy->next = curr;
    pre = dummy;
    
    while(curr) {
        
        if (curr->data % 2 == 0) {
            while(curr->data % 2 == 0 and curr->next and curr->next->data % 2 == 0) {
                Node* tmp = curr->next;
                curr->next = tmp->next;
                pre->next = tmp;
            }
            pre = curr->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printLinkedList(Node *head) {
  cout << "[";
  while (head != NULL) {
    cout << head -> data;
    head = head -> next;
    if (head != NULL)
      cout << " ";
  }
  cout << "]";
}

int test_case_number = 1;

void check(Node *expectedHead, Node *outputHead) {
  bool result = true;
  Node *tempExpectedHead = expectedHead;
  Node *tempOutputHead = outputHead;
  while (expectedHead != NULL && outputHead != NULL) {
    result &= (expectedHead -> data == outputHead -> data);
    expectedHead = expectedHead -> next;
    outputHead = outputHead -> next;
  }
  if (!(expectedHead == NULL && outputHead == NULL)) result = false;

  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printLinkedList(tempExpectedHead);
    cout << " Your output: ";
    printLinkedList(tempOutputHead);
    cout << endl;
  }
  test_case_number++;
}

Node* createLinkedList(vector<int> arr) {
  Node *head = NULL;
  Node *tempHead = head;
  for (auto &v : arr) {
    if (head == NULL) head = new Node(v), tempHead = head;
    else {
      head -> next = new Node(v);
      head = head -> next;
    }
  }
  return tempHead;
}

int main() {

  Node *head_1 = createLinkedList({1, 2, 8, 9, 12, 16});
  Node *expected_1 = createLinkedList({1, 8, 2, 9, 16, 12});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  Node *head_2 = createLinkedList({2, 18, 24, 3, 5, 7, 9, 6, 12});
  Node *expected_2 = createLinkedList({24, 18, 2, 3, 5, 7, 9, 12, 6});
  Node *output_2 = reverse(head_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
