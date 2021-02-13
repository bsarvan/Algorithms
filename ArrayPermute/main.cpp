//
//  main.cpp
//  ArrayPermute
//
//  Created by bsarvan on 03/09/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> arr) {
    for( auto a : arr) {
        cout<<a<<" ";
    }
    cout<<endl;
}

void ApplyPermutation(vector<int> *perm_ptr, vector<char> *A_ptr) {
    vector<int> &perm = *perm_ptr;
    vector<char> &A = *A_ptr;
    
    for(int i = 0; i < A.size(); i++) {
        int next = i;
        while(perm[next]>=0) {
            swap(A[i],A[perm[next]]);
            int temp = perm[next];
            perm[next] -= A.size();
            next = temp;
        }
    }

    cout<<"Permute Array - ";
    printVector(perm);
    cout<<endl;
    
    for_each(perm.begin(), perm.end(), [&](int &x) { x +=perm.size();});
    
    printVector(perm);
}


int main(int argc, const char * argv[]) {
    
    vector<int> perm = {3,1,2,0};
    vector<char> A = {'a','b','c','d'};
    std::cout << "Program to compute the permutation of the elements of array"<<endl;
    
    ApplyPermutation(&perm, &A);
    cout<<"Result after applying permutation"<<endl;
    for (auto c:A) {
        cout<<c<<" ";
    }
    
    cout<<endl;
    return 0;
}
