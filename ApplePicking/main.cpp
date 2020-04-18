//
//  main.cpp
//  ApplePicking
//
//  Created by bsarvan on 06/11/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 A girl is walking along an apple orchard with a bag in each hand.
 She likes to pick apples from each tree as she goes along, but is
 meticulous about not putting different kinds of apples in the same bag.
 
 Given an input describing the types of apples she will pass on her path,
 in order, determine the length of the longest portion of her path that
 consists of just two types of apple trees.
 
 For example, given the input [2, 1, 2, 3, 3, 1, 3, 5],
 the longest portion will involve types 1 and 3, with a length of four.
 
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



int longestStretch(vector<int> A) {
    unordered_set<int> SS;

    int i = 0;
    int maxLen = 0;
    int start = i;
    while(i < A.size()) {
        SS.emplace(A[i]);
        if (SS.size() <= 2) {
            int len = i - start;
            maxLen = max(maxLen, len);
            cout<<"Adding to set - "<<A[i]<<", Index - "<<i<<endl;
        } else {
//            cout<<"Clearing the set"<<endl;
            //SS.clear();
            SS.erase(A[start++]);
            cout<<"SS.Size() - "<<SS.size()<<endl;
//            start++;
//            i = start;
        }
        i++;
    }
    
    return maxLen - 1;
}


int longestStretch_v2(vector<int> S) {
    unordered_set<int> st;
    int ans = 0;
    int i=0;
    int j=0;
    size_t n = S.size();
    
    while(i<n && j < n) {
        //Allow adding only two elements to the set.
        //Hence checking for st.size() < 2.
        if (st.size() < 2) {
            st.emplace(S[j]);
            ans = max(ans, j - i);
            j++;
        } else {
            //Erase the start of the previous window
            st.erase(S[i++]);
        }
    }
    return ans;
}


int main() {
    //vector<int> A = {2,1,2,3,3,1,3,5};
    vector<int> A = {2,1,2,3,3,2,2,3,1,1,3,5};
    unordered_set<int> S;
    
    cout<<"Apple type picked in order - ";
    for (auto c:A) {
        cout<<c<<" ";
    }
    
    cout<<endl;
    
    int maxCount = longestStretch_v2(A);
    
//    int count = 0;
//    int maxCount = 0;
//
//    for (int i=0; i<A.size();i++) {
//        S.emplace(A[i]);
//        if (S.size() > 2 ) {
//            if (count > maxCount) {
//                maxCount = count;
//            }
//            cout<<"Clearing the set"<<endl;
//            S.clear();
//            S.emplace(A[i]);
//            count = 0;
//        }
//        count++;
//        cout<<"Value - "<<A[i]<<", Count - "<<count<<endl;
//    }
//
    cout<<"Length of longest portion - "<<maxCount<<endl;
    
    return 0;
    
}
