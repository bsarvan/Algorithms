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
void countSmallerRight(int A[], int len)
{
    set<int> s;
    int countSmaller[len];
    for (int i = len - 1; i >= 0; i--) {
        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);
        cout<<"It is "<<*it;
        countSmaller[i] = distance(s.begin(), it);
        cout<<", Distance - "<<countSmaller[i]<<endl;
    }
    
    for (int i = 0; i < len; i++)
        cout << countSmaller[i] << " ";
}

// Driver code
int main()
{
    int A[] = {12, 1, 2, 3, 0, 13, 4};
    int len = sizeof(A) / sizeof(int);
    countSmallerRight(A, len);
    return 0;
}

