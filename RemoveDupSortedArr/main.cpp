//
//  main.cpp
//  RemoveDupSortedArr
//
//  Created by bsarvan on 29/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> a, int len) {
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int removeDupsFromSortedArray(vector<int> &A) {
    // write_index is the index of the next non duplicate entry to write.
    int write_index = 1;
    for (int i = 1; i < A.size(); i++) {
        if (A[write_index - 1] != A[i]) {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to remove duplicated from sorted array"<<endl;
    
    vector<int> arr = {1,1,4,4,5,6,6};
    printArray(arr, 7);
//    int write_index = 1;
//    for(int i=1;i<7;i++) {
//        if(arr[write_index-1] != arr[i]) {
//            arr[write_index++] = arr[i];
//        }
//    }
    int len = removeDupsFromSortedArray(arr);
    printArray(arr, len);
    
    
    return 0;
}
