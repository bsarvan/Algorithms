//
//  main.cpp
//  CountSmallerUsingSTL
//
//  Created by bsarvan on 10/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//


// CPP program to find count of smaller
// elements on right side using set in C++
// STL.

#include <iostream>
#include <set>
using namespace std;



void printSet(set<int> S) {
    
    cout<<"Set - ";
    for(auto c: S){
        cout<<c<<" ";
    }
    cout<<endl;
}

void countSmallerRight(int A[], int len)
{
    set<int> s;
    int countSmaller[len];
    for (int i = len-1; i >= 0; i--) {
        s.insert(A[i]);
        printSet(s);
        auto it = s.lower_bound(A[i]);
        countSmaller[i] = distance(s.begin(), it);
        cout<<"A[i] - "<<A[i]<<", Num - "<<*it<<", Distance - "<<countSmaller[i]<<endl;
        cout<<"===================================================="<<endl;
    }
    
    for (int i = 0; i < len; i++)
        cout << countSmaller[i] << " ";
    
    cout<<endl;
}

// Algorithm to count the number of smaller elemments to the right
// with duplicates in the array
void countSmallerToRight_v2(vector<int> A) {
    vector<int> aux_array;
    vector<int> smallCount;
    
    for (int i = A.size() - 1; i >=0 i-- ) {
        aux_array.emplace_back(A[i]);
        auto it = lower_bound(A.begin(), A.end(), A[i]);
        int count = distance(A.begin(), it);
        smallCount.emplace_front(count);
    }
    
    for (auto s:smallCount) {
        cout<<s<<" ";
    }
    cout<<endl;
}

// Driver code
int main()
{
    //int A[] = {12, 1, 2, 3, 0, 13, 4};
    //int A[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    int A[] = {140, 476, 477, 386, 413, 200, 407, 181, 248, 276, 77, 248, 222, 144, 292, 197};
    int len = sizeof(A) / sizeof(int);
    countSmallerRight(A, len);
    return 0;
}

