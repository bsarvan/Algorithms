//
//  main.cpp
//  MaxProductSubArray
//
//  Created by bsarvan on 14/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Max Product SubArray
 
 Given an array that contains both positive and negative integers, find the product of the maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can be used.

 Examples:

 Input: arr[] = {6, -3, -10, 0, 2}
 Output:   180  // The subarray is {6, -3, -10}

 Input: arr[] = {-1, -3, -10, 0, 60}
 Output:   60  // The subarray is {60}

 Input: arr[] = {-2, -40, 0, -2, -3}
 Output:   80  // The subarray is {-2, -40}
 
 */
#include <iostream>
using namespace std;

//// Utility function to find minimum of two numbers
//int min(int x, int y) {
//    return (x < y) ? x : y;
//}
//
//// Utility function to find maximum of two numbers
//int max(int x, int y) {
//    return (x > y) ? x : y;
//}

// Function to return maximum product of a sub-array of given array
int maxProduct(int arr[], int n)
{
    // maintain two variables to store maximum and minimum product
    // ending at current index
    int max_ending = 0, min_ending = 0;

    // to store maximum product sub-array found so far
    int max_so_far = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        int temp = max_ending;

        // update maximum product ending at current index
        max_ending = max(arr[i], max(arr[i] * max_ending, arr[i] * min_ending));

        // update minimum product ending at current index
        min_ending = min(arr[i], min(arr[i] * temp, arr[i] * min_ending));

        max_so_far = max(max_so_far, max_ending);
    }

    // return maximum product
    return max_so_far;
}

// main function
int main(void)
{
    int arr[] = { -6, 4, -5, 8, -10, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"The maximum product of a sub-array is - "<<maxProduct(arr, n)<<endl;

    return 0;
}
