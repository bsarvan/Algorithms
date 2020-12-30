//
//  main.cpp
//  LargestDivisibleSubSet
//
//  Created by bsarvan on 11/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.
 
 For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].
 
 */
 
#include <iostream>
#include <vector>
using namespace std;


//// Prints largest divisble subset
//void findLargest(int arr[], int n)
//{
//    // We first sort the array so that all divisors
//    // of a number are before it.
//    sort(arr, arr+n);
//
//    // To store count of divisors of all elements
//    vector <int> divCount(n, 1);
//
//    // To store previous divisor in result
//    vector <int> path(n, -1);
//
//    // To store index of largest element in maximum
//    // size subset
//    int max_ind = 0;
//
//    // In i'th iteration, we find length of chain
//    // ending with arr[i]
//    for (int i=1; i<n; i++)
//    {
//        // Consider every smaller element as previous
//        // element.
//        cout<<"Dividend - a[i] - "<<arr[i]<<endl;
//        for (int j=0; j<i; j++)
//        {
//            cout<<"Divisor - arr[j] - "<<arr[j]<<endl;
//            if (arr[i]%arr[j] == 0)
//            {
//
//                if (divCount[i] < divCount[j] + 1)
//                {
//                    cout<<"divCount[i] - "<<divCount[i]<<", divCount[j] - "<<divCount[j]<<endl;
//                    divCount[i] = divCount[j]+1;
//                    path[i] = j;
//                }
//            }
//        }
//        cout<<"======================="<<endl;
//
//
//        // Update last index of largest subset if size
//        // of current subset is more.
//        if (divCount[max_ind] < divCount[i])
//            max_ind = i;
//    }
//
//
//    //Print the contents of prev
//
//    int m = 0;
//    while(m<n) {
//        cout<<path[m]<<" ";
//        m++;
//    }
//    cout<<endl;
//
//    // Print result
//    int k = max_ind;
//    while (k >= 0)
//    {
//        cout << arr[k] << " ";
//        k = path[k];
//    }
//
//    cout<<endl;
//
//}
//


// function to find the longest Subsequence
int largestSubset(int a[], int n)
{
    // Sort array in increasing order
    sort(a, a + n);
    
    // dp[i] is going to store size of largest
    // divisible subset beginning with a[i].
    int dp[n];
    
    // Since last element is largest, d[n-1] is 1
    dp[n - 1] = 1;
    
    // Fill values for smaller elements.
    for (int i = n - 2; i >= 0; i--) {
        
        // Find all multiples of a[i] and consider
        // the multiple that has largest subset
        // beginning with it.
        int mxm = 0;
        for (int j = i + 1; j < n; j++)
            if (a[j] % a[i] == 0)
                mxm = max(mxm, dp[j]);
        
        dp[i] = 1 + mxm;
    }
    
    // Return maximum value from dp[]
    return *max_element(dp, dp + n);
}

// Prints largest divisible subset
void findLargest(int arr[], int n)
{
    // We first sort the array so that all divisors
    // of a number are before it.
    sort(arr, arr+n);

    // To store count of divisors of all elements
    vector <int> divCount(n, 1);

    // To store previous divisor in result
    vector <int> prevDivisor(n, -1);

    // To store index of largest element in maximum
    // size subset
    int max_ind = 0;

    // In i'th iteration, we find length of chain
    // ending with arr[i]
    for (int i=1; i<n; i++)
    {
        // Consider every smaller element as previous
        // element.
        for (int j=0; j<i; j++)
        {
            if (arr[i]%arr[j] == 0)
            {
                cout<<arr[i]<<" % "<<arr[j]<<endl;
                if (divCount[i] < divCount[j] + 1)
                {
                    divCount[i] = divCount[j]+1;
                    cout<<"Updating the previous divisor for "<<arr[i]<<" : "<<j<<endl;
                    prevDivisor[i] = j;
                }
            }
        }
        
        cout<<"Numnber of divisors at each i - ";
        for (auto p:divCount) {
            cout<<p<<" ";
        }
        cout<<endl;
        // Update last index of largest subset if size
        // of current subset is more.
        if (divCount[max_ind] < divCount[i])
            max_ind = i;
    }
    
    cout<<"Maximum Index - "<<max_ind<<endl;

    // Print result
    int k = max_ind;
    while (k >= 0)
    {
        cout << arr[k] << " ";
        k = prevDivisor[k];
    }
    
    cout<<endl;
}

// driver code to check the above function
int main()
{
//    int a[] = { 1, 3, 6, 13, 17, 18 };
//    int a[] = {3, 5, 10, 22, 20, 30};
    int a[] = {1,2,7,4};
    cout<<"Input array is - ";
    for(auto &c:a) {
        cout<<c<<" ";
    }
    cout<<endl;
    int n = sizeof(a) / sizeof(a[0]);
    findLargest(a,n);
    return 0;
}

