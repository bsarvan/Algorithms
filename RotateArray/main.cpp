//
//  main.cpp
//  RotateArray
//
//  Created by bsarvan on 12/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 
 Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.
 
 */
int main(int argc, const char * argv[]) {
    cout<<"Program to rotate an array by k value"<<endl;
    int k = 2;
    vector<int> V = {1,2,3,4,5,6};
    
    cout<<"Input Array - ";
    for (auto v:V) {
        cout<<v<<" ";
    }
    cout<<endl;
    
    reverse(V.begin()+V.size()-k,V.end());
    cout<<"Partial rotated array B - ";
    for (auto v:V) {
        cout<<v<<" ";
    }
    cout<<endl;
    
    reverse(V.begin(),V.end() - k);
    cout<<"Partial rotated array A - ";
    for (auto v:V) {
        cout<<v<<" ";
    }
    cout<<endl;
    
    reverse(V.begin(),V.end());
    cout<<"Final Array rotated by k elements is - ";
    for (auto v:V) {
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
