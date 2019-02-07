//
//  main.cpp
//  MaxGap
//
//  Created by bsarvan on 31/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int maximumGap(const vector<int> &A) {
    
    vector<int>l;
    int i;
    int mini=A[0];
    l.push_back(A[0]);
    
    for(i=1;i<A.size();i++)
        l.push_back(min(A[i],l[i-1]));
    
    for(i=0;i<l.size();i++)
        cout<<l[i]<<" ";
    
    cout<<endl;
    
    mini=A[A.size()-1];
    
    vector<int>r(A.size());
    
    r[A.size()-1]=A[A.size()-1];
    
    for(i=A.size()-2;i>=0;i--)
        r[i]=max(r[i+1],A[i]);
    
    for(i=0;i<r.size();i++)
        cout<<r[i]<<" ";
    
    cout<<endl;
    
    int diff = 0;
    int j=0;
    i=0;
    while(i<A.size() && j<A.size())
    {
        if(l[i]<=r[j])
        {
            diff=max(diff,j-i);
            j++;
        }
        else
            i++;
    }
    
    
    return diff;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Programm to find the maximum gap between elements of array"<<endl;
    vector<int> A = {3,5,4,2};
    
    int result = maximumGap(A);
    
    cout<<"The maximum gap is "<<result<<endl;
    
    return 0;
}
