//
//  main.cpp
//  MatrixSearch
//
//  Created by bsarvan on 01/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> A, int start, int end, int key){
    int mid = start + (end-start)/2;
    if(start <= end){
        if(A[mid] == key){
            return 1;
        }
        else if(A[mid] > key){
            return binarySearch(A, start, mid-1, key);
        }
        else{  // A[mid] < key
            return binarySearch(A, mid+1, end, key);
        }
    }
    return 0;
}

int binarySearch2(vector<int> a,int low, int high, int val) {
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(a[mid] == val) {
            return mid;
        } else if (a[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}


int searchMatrix(vector<vector<int>> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows = A.size();
    int cols = A[0].size();
    
    for(int i = 0; i < rows; i++){
        if((A[i][0] <= B) && (A[i][cols-1] >= B)){
            if(binarySearch2(A[i], 0, cols-1, B)){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to find a element in m x n matrix"<<endl;
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    
    int result = searchMatrix(mat, 16);
    cout<<"Result of search in matrix is "<<result<<endl;
    
    return 0;
}
