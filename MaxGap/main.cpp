//
//  main.cpp
//  MaxGap
//
//  Created by bsarvan on 31/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//
/*
 
 
 Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
 
 If there is no solution possible, return -1.
 
 Example :
 
 A : [3 5 4 2]
 
 Output : 2
 for the pair (3, 4)

 
 */



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
    
    vector<int> r(A.size());
    
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

void maxGapV2(vector<int> V) {
    vector<pair<int,int>> vp;
    
    for (int i = 0; i<V.size(); i++) {
        vp.emplace_back(make_pair(V[i], i));
    }
    
    for(auto v:vp) {
        cout<<v.first<<"->"<<v.second<<endl;
    }
    
    sort(vp.begin(), vp.end());
    
    cout<<"Sorted output here is "<<endl;
    
    for(auto v:vp) {
        cout<<v.first<<"->"<<v.second<<endl;
    }
    
    cout<<"Computing the max gap"<<endl;
    int i = 0;
    int j = 1;
    int diff = 0;
    while(i<vp.size() && j<vp.size()){
        cout<<"comparing - "<<vp[i].second<<" "<<vp[j].second<<endl;
        if (vp[i].second < vp[j].second) {
            diff = max(diff, vp[j].second - vp[i].second);
//            j++;
        } else {
            i++;
        }
        j++;
    }
    
    cout<<"Gap - "<<diff<<endl;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Programm to find the maximum gap between elements of array"<<endl;
    //vector<int> A = {3,5,4,2};
    vector<int> A = {10,4,2,5,12,8,9,7};
    
//    int result = maximumGap(A);
//
//    cout<<"The maximum gap is "<<result<<endl;
    
    maxGapV2(A);
    
    return 0;
}
