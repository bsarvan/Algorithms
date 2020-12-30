//
//  main.cpp
//  MatrixMedian
//
//  Created by bsarvan on 24/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int min = A[0][0], max = A[0][0];
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][m-1] > max) max = A[i][m-1];
    }
    
    int element = (n * m + 1) / 2;
    cout<<"Element - "<<element<<endl;
    
    while (min < max) {
        int mid = min + (max - min) / 2;
        cout<<"min-"<<min<<",max-"<<max<<",mid-"<<mid<<endl;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            //Find count of elements smaller than mid
            cnt += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0];
            cout<<"Row - "<<i<<";cnt - "<<cnt<<endl;
        }
        if (cnt < element)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find median of matrix"<<endl;
    vector<vector<int>> A = {{1,3,5},{2,6,9},{3,6,9}};
    int median = findMedian(A);
    cout<<"Median of Matrix is - "<<median<<endl<<endl;
    
    cout<<A[0][3]<<endl;
    long cnt = upper_bound(&A[0][0], &A[0][3], 5) - &A[0][0];
    cout<<"Count - "<<cnt<<endl<<endl;
    
    return 0;
}
