//
//  main.cpp
//  Counting Sort
//
//  Created by bsarvan on 17/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


int findMaxInArray(int A[], int N) {
    int max = 0;
    for(int k=0;k<N;k++) {
        if (A[k]>max) {
            max = A[k];
        }
    }
    return max;
    
}

void printArray(int a[], int n) {
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test Counting Sort"<<endl;
    
    int A[] = {1, 2, 1, 3, 1, 5, 2, 0, 2, 5};
    
    int count[6] = {0};
    int finalArr[10] = {0};
    
    int n = sizeof(A) /  sizeof(int);
    
    cout<<"Input Array is - ";
    printArray(A, n);
    
    int K = findMaxInArray(A, n);
    cout<<"Max value of the element in the array  - "<<K<<endl;
    
    //Count number of occurences for each element in input array
    for(int i=0;i<n;i++) {
        count[A[i]]++;
    }
    
    printArray(count, 6);

    for(int j=1;j<=K;j++){
        count[j] += count[j-1];
    }
   
     printArray(count, 6);
    
    for(int m=n-1;m>=0;m--) {
        finalArr[count[A[m]] - 1] = A[m];
        count[A[m]]--;
    }
    printArray(finalArr, n);
    
    return 0;
}
