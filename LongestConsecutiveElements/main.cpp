//
//  main.cpp
//  LongestConsecutiveElements
//
//  Created by bsarvan on 22/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
 For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
 
 Your algorithm should run in O(n) complexity.
 
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 
 Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 Examples:
 
 Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
 Output: 4
 The subsequence 1, 3, 4, 2 is the longest subsequence
 of consecutive elements
 
 */
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
    
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
    
    // check each possible sequence from the start
    // then update optimal length
    for (int i=0; i<n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i]-1) == S.end())
        {
            // Then check for next elements in the
            // sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            
            // update  optimal length if this length
            // is more
            ans = max(ans, j - arr[i]);
        }
    }
    
    // If the values in the set are 1,2,3,4
    // Maximum length is computed as 4 - 1 = 3.
    // Hence plus one to computed length
    return ans + 1;
}

int main(int argc, const char * argv[]) {
    cout<<"Coding Challenge - Find the longest consecutive elements in the stream of numbers"<<endl;
    vector<int> v = {100,4,200,1,3,2};
    
    cout<<"Vector Elements - ";
    for (auto c:v) {
        cout<<c<<" ";
    }
    cout<<endl;
    
    sort(v.begin(), v.end());
    
    int max_len = 0;
    int count = 0;
    for (int i=0; i<v.size() - 1;i++) {
        if (v[i] + 1 == v[i+1]) {
            count++;
        } else {
            max_len = max(max_len, count);
        }
    }
    
    cout<<"Max Len - "<<max_len<<endl;
    return 0;
}
