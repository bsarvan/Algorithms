//
//  main.cpp
//  SearchingAlgorithms
//
//  Created by bsarvan on 09/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &A, int d) {
    int left = 0;
    int ans = 0;
    int right = A.size() - 1;
    
    while(left <= right) {
        int mid = (left +  right)/2;
        if (A[mid] < d) {
            left = mid + 1;
        } else if (A[mid] == d) {
            return (mid);
        } else {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}




int main(int argc, const char * argv[]) {
    
    cout<<"Program to test Searching Algorithms"<<endl;
    vector<int> V = {2,4,7,9,9,10};
    int index = binarySearch(V, 3);
    cout<<"Number found / Inserted at index "<<index<<endl;
    
    
    return 0;
}
