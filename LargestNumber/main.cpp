//
//  main.cpp
//  LargestNumber
//
//  Created by bsarvan on 17/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int comp(string a, string b){
    return a + b > b + a;
}

string LargestNumber(vector<int> A){
    vector<string> B;
    bool allZero = true;
    string b;
    
    for(int i=0;i<A.size();i++){
        B.push_back(to_string(A[i]));
        if(A[i] != 0)
            allZero = false;
    }
    
    if (allZero)
        return "0";
    
    sort(B.begin(),B.end(),comp);
    
    for(int j=0;j<B.size();j++){
        b = b + B[j];
    }
    
    return(b);
}


int main(int argc, const char * argv[]) {
    vector<int> vec = {8,4,5,7,3,0};
    cout<<"Program to arrange the elements of array to Largest Number"<<endl;
    cout<<LargestNumber(vec)<<endl;
    return 0;
}
