//
//  main.cpp
//  HeapSort
//
//  Created by bsarvan on 17/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define LEFT(i) 2*i
#define PARENT(i) i/2
#define RIGHT(i) (2*i + 1)


void MaxHeapify(vector<int> &A, int i, int n) {
    int l = LEFT(i);
    int r = RIGHT(i);
    
    int largest = i;
    
    if(l < n && A[l] > A[i])
        largest = l;
    else
        largest = i;
    
    if(r < n && A[r] > A[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(A[largest], A[i]);
        MaxHeapify(A, largest, n);
    }
}

void printArray(vector<int> A) {
    cout<<endl<<"Contents of Array - ";
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return;
}


void BuildMaxHeap(vector<int> &A) {
    int n = A.size();
    for (int i = n/2;i>=0;i--) {
        MaxHeapify(A, i, n);
    }
}

void HeapSort(vector<int> &A, int n) {
    for(int i=n; i>=0;i--) {
        swap(A[0], A[i]);
        MaxHeapify(A, 0, i);
    }
    return;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to test Heap Sorting"<<endl;
    
    vector<int> A = {16,14,17,18,11};
    
    printArray(A);
    
    BuildMaxHeap(A);
    
    printArray(A);
    
    HeapSort(A, A.size()-1);
    
    printArray(A);
    
    cout<<endl;
    return 0;
}
