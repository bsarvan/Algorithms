//
//  main.cpp
//  pivotPartition
//
//  Created by bsarvan on 13/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int partition(int left, int right,  int pivot_index, vector<int> *A_ptr)
{
    vector<int> &A = *A_ptr;
    int pivot_value = A[pivot_index];
    int new_pivot_index = A[left];
    
    swap(A[pivot_index], A[right]);
    for (int i = left;i<right;i++){
        if(A[i]>pivot_value) {
            swap(A[i],A[new_pivot_index]);
        }
    }
    swap(A[right],A[new_pivot_index]);
    
    return(new_pivot_index);
}
int main(int argc, const char * argv[]) {
    cout<<"Program to test pivot partiti on"<<endl;
    vector<int> arr = {2,4,7,5,3,1};
    int low = 0, high = arr.size(), random_index = 3;
    int new_pivot_index = partition(low,high,random_index, &arr);
    
    for(auto iter = arr.begin();iter < arr.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl<<"New Pivot Index = "<<new_pivot_index<<endl;
    cout<<endl;
    return 0;
}
