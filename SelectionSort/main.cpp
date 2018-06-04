//
//  main.cpp
//  SelectionSort
//
//  Created by bsarvan on 13/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void selection_sort(int A[], int n){
    int minimum;
    for ( int i = 0;i < n-1; i++) {
        minimum = i;
        for (auto j = i + 1; j < n;j++) {
            if(A[j]<A[minimum]){
                minimum = j;
            }
        }
        swap(A[i], A[minimum]);
    }
    for(int i = 0;i<n;i++) {
        cout<<A[i]<<" ";
    }
        cout<<endl;
}
int main(int argc, const char * argv[]) {
    cout<<"Program for selection sort"<<endl;
    int A[] = {7,5,4,2};
    int n = 4;
    selection_sort(A,n);
    return 0;
}
