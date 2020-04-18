//
//  main.cpp
//  MaxSetSubarray
//
//  Created by bsarvan on 03/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> maxset(vector<int> &A) {
    long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, sumTillNow = INT_MIN, maxTillNow=INT_MIN;
    int i=0;
    
    while(i<A.size()){
        if(A[i]>=0){
            start = i;
            sumTillNow =0;
            length =0;
            
            while(A[i]>=0 && i<A.size()){
                sumTillNow +=A[i];
                i++;
            }
            end = i-1;
            
            if( ( sumTillNow>maxTillNow ) || ( sumTillNow==maxTillNow && end - start +1 < ansLength ) ){
                ansStart = start;
                ansEnd = end;
                ansLength = start + end -1 ;
                maxTillNow = sumTillNow;
            }
        }
        i++;
        
    }
    vector <int> ans;
    for(int i=ansStart; i<=ansEnd;i++){
        ans.push_back(A[i]);
    }
    
    return ans;
}


vector<int> maxset_v2(vector<int> &A) {
    long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, sumTillNow = 0, maxTillNow=INT_MIN;
    int i=0;
    
    while(i<A.size()){
    
        start = i;
        sumTillNow =0;
        length =0;
        
        cout<<"max till now - "<<maxTillNow<<", sum till now - "<<sumTillNow<<endl;
        while(maxTillNow < sumTillNow && i<A.size()){
            cout<<"max till now - "<<maxTillNow<<", sum till now - "<<sumTillNow<<endl;
            cout<<"Here"<<endl;
            sumTillNow +=A[i];
            i++;
        }
        end = i-1;
        
        if( ( sumTillNow>maxTillNow ) || ( sumTillNow==maxTillNow && end - start +1 < ansLength ) ){
            ansStart = start;
            ansEnd = end;
            ansLength = start + end -1 ;
            maxTillNow = sumTillNow;
        }
    
        i++;
        
    }
    vector <int> ans;
    for(int i=ansStart; i<=ansEnd;i++){
        ans.push_back(A[i]);
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    vector<int> vec = {1, 2, 5, -7, 2, 3};
    //vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> result = maxset(vec);
    
    for(auto c:result) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
