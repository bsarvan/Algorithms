//
//  main.cpp
//  FindFirstPositive
//
//  Created by bsarvan on 19/05/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 Given an unsorted integer array, find the smallest missing positive integer.
 
 Example 1:
 
 Input: [1,2,0]
 Output: 3
 Example 2:
 
 Input: [3,4,-1,1]
 Output: 2
 Example 3:
 
 Input: [7,8,9,11,12]
 Output: 1
 
 */
/* C++ program to find the smallest positive missing number */
#include <iostream>
#include <vector>
using namespace std;

/* Utility to swap to integers */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


/* Utility function that puts all
 non-positive (0 and negative) numbers on left
 side of arr[] and return count of such numbers */
int segregate (int arr[], int size)
{
    int j = 0, i;
    for(i = 0; i < size; i++)
    {
        if (arr[i] <= 0)
        {
            swap(&arr[i], &arr[j]);
            j++; // increment count of non-positive integers
        }
    }
    
    return j;
}

/* Find the smallest positive missing number
 in an array that contains all positive integers */
int findMissingPositive(int arr[], int size)
{
    int i;
    
    cout<<"Before - ";
    printArray(arr, size);
    // Mark arr[i] as visited by making arr[arr[i] - 1] negative.
    // Note that 1 is subtracted because index start
    // from 0 and positive numbers start from 1
    for(i = 0; i < size; i++)
    {
        if(abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) {
            cout<<"arr[abs(arr[i]) - 1] : "<<arr[ abs(arr[i]) - 1]<<" , i : "<<i<<endl;
            cout<<"In here "<<arr[i]<<endl;
            arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1];
        }
    }
    
    cout<<"After - ";
    printArray(arr, size);
    
    // Return the first index value at which is positive
    for(i = 0; i < size; i++)
        if (arr[i] > 0)
            // 1 is added because indexes start from 0
            return i+1;
    
    return size+1;
}

/* Find the smallest positive missing
 number in an array that contains
 both positive and negative integers */
int findMissing(int arr[], int size)
{
    // First separate positive and negative numbers
    int shift = segregate (arr, size);
    
    // Shift the array and call findMissingPositive for
    // positive part
    return findMissingPositive(arr + shift, size - shift);
}


void printVector(vector<int> arr) {
    for(auto a : arr) {
        cout<<a<<" ";
    }
    cout<<endl;
}

int SmallestPositiveMissingNumber(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        while(arr[i] != i + 1 and arr[i] < arr.size()) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    for( int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    
    return -1;
}




// Driver code
int main()
{
    //int arr[] = {0, 10, 2, -10, -20};
    //int arr[] = {2,4,3,-1,10};
//    int arr[] = {1,8,7,5};
//    //int arr[] = {1,2,0};
//    printArray(arr, 3);
//    int arr_size = sizeof(arr)/sizeof(arr[0]);
//    int missing = findMissing(arr, arr_size);
    vector<int> arr1 = {1,8,7,5};
    int missing = SmallestPositiveMissingNumber(arr1);
    cout << "The smallest positive missing number is " << missing<<endl;
    return 0;
}

// This is code is contributed by rathbhupendra
