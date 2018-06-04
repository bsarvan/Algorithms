//
//  main.cpp
//  MergeTwoSortedArray
//
//  Created by bsarvan on 30/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

void merge(int a[], int b[], int lastA, int lastB) {
    int indexA = lastA - 1;/* Index of last element in array a*/
    int indexB = lastB - 1;/* Index of last element in array b*/
    int indexMerged = lastB + lastA - 1;/* end of merged array*/
    /* Merge a and b, starting from the last element in each*/
    while (indexB >= 0) {
        /* endofais>thanendofb*/
        if (indexA >= 0 && a[indexA] > b[indexB]) {
            a[indexMerged] = a[indexA]; //
            indexA--;
        } else {
            a[indexMerged] = b[indexB]; //
            indexB--;
        }
        indexMerged--; // move indices
    }
    return;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to merge two sorted array"<<endl;
    int A[10] = {2,4,6,8};
    int B[] = {1,3,5,7};
    
    merge(A,B,4,4);
    
    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
