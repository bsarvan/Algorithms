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

void printArray(int a[], int len) {
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to remove duplicated from sorted array"<<endl;
    
    int arr[7] = {1,1,4,4,5,6,6};
    printArray(arr, 7);
    int write_index = 1;
    for(int i=1;i<7;i++) {
        if(arr[write_index-1] != arr[i]) {
            arr[write_index++] = arr[i];
        }
    }
    printArray(arr, write_index);
    
    
    return 0;
}
