//
//  main.cpp
//  PeakAndValley
//
//  Created by bsarvan on 29/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int findMaxIndex(vector<int> A, int a, int b, int c) {
    int maxIndex = INT_MIN;
    
    if (A[a] > A[b])
        maxIndex = a;
    else
        maxIndex = b;
    
    if (A[maxIndex] < A[c])
        maxIndex = c;
    
    return maxIndex;
}

int main(int argc, const char * argv[]) {
    
//    vector<int> A = {9, 1, 0, 4, 8, 7};
    vector<int> A = {5, 1, 3, 2, 4};
    
    cout<<"Input Array - ";
    for(auto c:A)
        cout<<c<<" ";
    
    cout<<endl;
    
    sort(A.begin(), A.end());
    
    for (int i = 1; i < A.size(); i+=2) {
        int maxIndex = findMaxIndex(A, i-1, i, i+1);
        
        if (i != maxIndex) {
            swap(A[i], A[maxIndex]);
        }
    }
    
    cout<<"Peak And Valley Array - ";
    for(auto c:A)
        cout<<c<<" ";
    
    cout<<endl;
    
    return 0;
}
