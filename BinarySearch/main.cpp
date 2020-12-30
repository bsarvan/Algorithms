//
//  main.cpp
//  BinarySearch
//
//  Created by bsarvan on 30/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

int binarysearch(int a[],int low, int high, int val) {
    while(low <= high) {
        cout<<"Before - Low - "<<low<<"   High - "<<high<<endl;
        int mid = low + (high - low)/2;
        if(a[mid] == val) {
            return mid;
        } else if (a[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        cout<<"After - Low - "<<low<<"   High - "<<high<<endl;
    }
    return -1;
}


int binarysearch(vector<int> arr) {
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    
    while(low <= high) {
        if (arr[mid] == )
        
    }
}
int main(int argc, const char * argv[]) {
    cout<<"Program for binary search"<<endl;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int val = 3;
    int index = binarysearch(arr, 0, 9, val);
    cout<<"Index of "<<val<<" is "<<index<<endl;
    return 0;
}
