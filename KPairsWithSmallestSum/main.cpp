//
//  main.cpp
//  KPairsWithSmallestSum
//
//  Created by bsarvan on 09/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 
 You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 
 Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 
 Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 
 Example 1:
 
 Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 Output: [[1,2],[1,4],[1,6]]
 Explanation: The first 3 pairs are returned from the sequence:
 [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 Example 2:
 
 Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 Output: [1,1],[1,1]
 Explanation: The first 2 pairs are returned from the sequence:
 [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 
 
 Algorithm -
 We one by one find k smallest sum pairs, starting from least sum pair. The idea is to keep track of all elements of arr2[]
 which have been already considered for every element arr1[i1] so that in an iteration we only consider next element.
 For this purpose, we use an index array index2[] to track the indexes of next elements in the other array. It simply means
 that which element of second array to be added with the element of first array in each and every iteration. We increment
 value in index array for the element that forms next minimum value pair.
 */

#include <iostream>
#include <vector>
using namespace std;



void printVector(vector<int> V) {
    for (auto v:V)
        cout<<v<<" ";
    
    cout<<endl;
}

vector<pair<int,int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<pair<int,int>> R;

    int n1 = nums1.size();
    int n2 = nums2.size();

    // Stores current index in arr2[] for
    // every element of arr1[]. Initially
    // all values are considered 0.
    // Here current index is the index before
    // which all elements are considered as
    // part of output.
    vector<int> index2(n2,0);

    while(k > 0) {
        int min_sum = INT_MAX;
        int min_index = 0;
        
        for(int i = 0; i < n2; i++) {
            cout<<"nums1 - "<<nums1[i]<<", nums2 - "<<nums2[index2[i]]<<endl;
            if (index2[i] < n2 && ((nums1[i] + nums2[index2[i]]) < min_sum)) {
                min_index = i;
                min_sum = nums1[i] + nums2[index2[i]];
            }
        }
        
        R.emplace_back(make_pair(nums1[min_index], nums2[index2[min_index]]));
        index2[min_index]++;
        cout<<"Index2 - "; printVector(index2);
        k--;
        
    }
    return R;
}


#if 0
vector<pair<int,int>> kSmallestPairs(vector<int> &A, vector<int> &B, int k) {
    vector<pair<int,int>> pairs;
    vector<pair<int,int>> R;
    
    for(int i = 0; i < A.size() - 1;i++) {
        for(int j = 0; j < B.size(); j++) {
            pairs.emplace_back(make_pair(A[i],B[j]));
        }
    }
    
    sort(pairs.begin(),pairs.end());
    
    for(int i = 0;i<k;i++) {
        R.emplace_back(pairs[i]);
    }
    return R;
}
#endif

int main(int argc, const char * argv[]) {
    vector<int> A = {5,9,11};
    vector<int> B = {2,4,8};
    
    vector<pair<int,int>> result = kSmallestPairs(A,B,3);
    for(auto c:result) {
        cout<<c.first<<", "<<c.second<<endl;
    }
    return 0;
}
