//
//  main.cpp
//  PrintRepeatedNumber
//
//  Created by bsarvan on 29/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast) {
        cout<<"Slow Index - "<<slow<<"  Fast Index - "<<A[fast]<<endl;
        slow = A[slow];
        fast = A[A[fast]];
        cout<<"Loop1 - Slow - "<<slow<<"  Fast - "<<fast<<endl;
    }
    fast = 0;
    while (slow != fast) {
        cout<<"Loop2 - Slow - "<<slow<<"  Fast - "<<fast<<endl;
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}
int main(int argc, const char * argv[]) {
    vector<int> v = {3,4,5,2,5,1,7,8};
    cout<<"Program to find the repeating number in a unsorted array"<<endl;
    
    cout<<"The input array is - ";
    for(auto c:v){
        cout<<c<<" ";
    }
    cout<<endl;
    
    int rep = repeatedNumber(v);
    cout<<"The repeating number is "<<rep<<endl;
    return 0;
}
