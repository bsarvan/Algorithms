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


void ApplyPermutation(vector<int> *perm_ptr, vector<char> *A_ptr) {
    vector<int> &perm = *perm_ptr;
    vector<char> &A = *A_ptr;
    
    for(int i = 0; i < A.size(); i++) {
        int next = i;
        while(perm[next]>=0) {
            cout<<"Next is - "<<next<<endl;
            //cout<<"A["<<i<<"] - "<<A[i]<<",  A["<<perm[next]<<"]"<<" - "<<A[perm[next]]<<endl;
            swap(A[i],A[perm[next]]);
            int temp = perm[next];
            perm[next] -= A.size();
            next = temp;
        }
    }

    cout<<"Permute Array - ";
    for (auto v:perm) {
        cout<<v<<" ";
    }
    cout<<endl;
    
    for_each(perm.begin(), perm.end(), [&](int &x) { x +=perm.size();});
}


int main(int argc, const char * argv[]) {
    
    vector<int> perm = {3,1,2,0};
    vector<char> A = {'a','b','c','d'};
    std::cout << "Program to compute the permutation of the elements of array"<<endl;
    
    ApplyPermutation(&perm, &A);
    
    for (auto c:A) {
        cout<<c<<" ";
    }
    
    cout<<endl;
    return 0;
}
