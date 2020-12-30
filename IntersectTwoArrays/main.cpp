//
//  main.cpp
//  IntersectTwoArrays
//
//  Created by bsarvan on 01/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectArrays(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> intersect;
    
    while(i < a.size() && j < b.size()) {
        cout<<"A - "<<a[i]<<", B - "<<b[j]<<endl;
        if(a[i] == b[j] && (i==0 || a[i] != a[i-1])) {
            intersect.emplace_back(a[i]);
            i++;
            j++;
        } else if( a[i] < b[j]) {
            i++;
        } else
            j++;
    }
    return intersect;
}

int main(int argc, const char * argv[]) {
    cout<<"Algorithm to find the intersect of two sorted arrays"<<endl;
    vector<int> A = {2,3,3,5,7,11};
    vector<int> B = {3,3,7,15,31};
    
    cout<<"The intersection of two arrays A and B is "<<endl;
    vector<int> result = intersectArrays(A,B);
   
    cout<<"Intersected Array - ";
    for(auto c:result){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
