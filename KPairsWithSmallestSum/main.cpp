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
 
 */

#include <iostream>
#include <vector>
using namespace std;



vector<pair<int,int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<pair<int,int>> R;

    int n1 = nums1.size() - 1;
    int n2 = nums2.size() - 1;

    vector<int> index2(n2,0);

    while(k > 0) {
        int min_sum = INT_MAX;
        int min_index = 0;
        
        for(int i = 0; i < n2; i++) {
            if (index2[i] < n2 && ((nums1[i] + nums2[index2[i]]) < min_sum)) {
                min_index = i;
                min_sum = nums1[i] + nums2[index2[i]];
            }
        }
        
        R.emplace_back(make_pair(nums1[min_index], nums2[index2[min_index]]));
        index2[min_index]++;
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
    vector<int> A = {1,1,4};
    vector<int> B = {1,2,6};
    
    vector<pair<int,int>> result = kSmallestPairs(A,B,2);
    for(auto c:result) {
        cout<<c.first<<", "<<c.second<<endl;
    }
    return 0;
}
