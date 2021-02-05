//
//  main.cpp
//  NextGreaterElement
//
//  Created by bsarvan on 14/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* prints element and NGE pair for all
 elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;
    
    /* push the first element to stack */
    s.push(arr[0]);
    
    // iterate for rest of the elements
    for (int i=1; i<n; i++)
    {
        int next = arr[i];
        
        if (s.empty() == false)
        {
            // if stack is not empty, then
            // pop an element from stack
            int element = s.top();
            cout<<"Popped element from the stack - "<<element<<endl;
            s.pop();
            
            /* If the popped element is smaller
             than next, then
             a) print the pair
             b) keep popping while elements are
             smaller and stack is not empty */
            while (element < next)
            {
                cout << element << " --> " << next
                << endl;
                if (s.empty() == true)
                    break;
                element = s.top();
                s.pop();
            }
            
            /* If element is greater than next,
             then push the element back */
            if (element > next) {
                cout<<"Pushing element back to Stack - "<<element<<endl;
                s.push(element);
            }
        }
        
        /* push next to stack so that we can find
         next greater for it */
        cout<<"Pushing next on the stack - "<<next<<endl;
        cout<<"========================================"<<endl;
        s.push(next);
    }
    
    /* After iterating over the loop, the remaining
     elements in stack do not have the next greater
     element, so print -1 for them */
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void nextGreater(vector<int> A) {
  stack<int> st;
  
  for (int i = 0; i < A.size(); i++) {
    
    if (!st.empty()) {
      while(!st.empty() and st.top() < A[i]) {
        cout<<st.top()<<" -> "<<A[i]<<endl;
        st.pop();
      }
    }
    st.push(A[i]);
  }
  
  while(!st.empty()) {
    cout<<st.top()<<" -> -1"<<endl;
    st.pop();
  }
  
  return;
}


/* Driver program to test above functions */
int main()
{
    //int arr[] = {11, 5, 7, 13, 21, 3};
//    int arr[] = {11, 5, 7, 1, 2, 13};
    vector<int> input = {11, 5, 7, 1, 2, 13};
    
//    int n = sizeof(arr)/sizeof(arr[0]);
//    printArray(arr, n);
//    printNGE(arr, n);
    
    nextGreater(input);
    return 0;
}


