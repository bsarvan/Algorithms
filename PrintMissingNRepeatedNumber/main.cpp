//
//  main.cpp
//  PrintMissingNRepeatedNumber
//
//  Created by bsarvan on 14/06/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    
    long long int len = A.size();
    long long int sumOfN = (len * (len+1) ) /2, sumOfNsq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber1=0, missingNumber2=0;
    
    cout<<"Actual SumofN - "<<sumOfN<<endl;
    cout<<"Actual SumofSq - "<<sumOfNsq<<endl;
    
    for(int i=0;i<A.size(); i++){
        sumOfN -= (long long int)A[i];
        sumOfNsq -= (long long int)A[i]*(long long int)A[i];
    }
    
    cout<<"SumN - "<<sumOfN<<endl;
    cout<<"SumofNSq - "<<sumOfNsq<<endl;
    
    missingNumber1 = (sumOfN + sumOfNsq/sumOfN)/2;
    cout<<"Missing Number - "<<missingNumber1<<endl;
    missingNumber2= missingNumber1 - sumOfN;
    cout<<"Repeated Number - "<<missingNumber2<<endl;
    vector <int> ans;
    ans.push_back(missingNumber2);
    ans.push_back(missingNumber1);
    return ans;
}


int main(int argc, const char * argv[]) {
    cout<<"Program to find the repeated and missing number in vector"<<endl;
    vector<int> A = {1,2,3,3,5};
    
    for(auto c:A){
        cout<<c<<" ";
    }
    cout<<endl;
    
    vector<int> result = repeatedNumber(A);
    
    cout<<"The Repeated and Missing Numbers are - "<<endl;
    for(int i = 0; i<result.size();i++) {
        cout<<result[i]<<endl;
    }
    
    return 0;
}
