//
//  main.cpp
//  MoveAllZerosToLeft
//
//  Created by Bharat Sarvan on 15/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given an integer array, move all elements that are 0 to the left while maintaining the order of other elements in the array. The array has to be modified in-place.
 
 Array Input - [1,10,20, 0, 59, 63, 0, 88, 0]
 */
#include <iostream>
#include <vector>
using namespace std;


void MoveAllZeros(vector<int> &nums) {
    if (nums.size() == 0) {
        return;
    }
    
    int write_index = nums.size() - 1;
    size_t nums_size = nums.size() - 1;

    for(int index = nums_size; index >=0 ; index-- ) {
        if (nums[index] != 0) {
            nums[write_index--] = nums[index];
        }
    }
    
    while(write_index >= 0 ) {
        nums[write_index--] = 0;
    }
    return;
}


int main(int argc, const char * argv[]) {
   
    cout<<"Algorithm the move all the zeros at the beginning of the array"<<endl;
    vector<int> A = {1, 10, 20, 0, 59, 63, 0, 88, 0};
    
    MoveAllZeros(A);
    
    for (auto a:A) {
        cout<<a<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
