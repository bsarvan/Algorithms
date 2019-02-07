//
//  main.cpp
//  NumOfBitsSet
//
//  Created by bsarvan on 09/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    cout<<"Program to count number of bits set "<<endl;
    int number;
    
    cout<<"Enter the number - ";
    cin>>number;
    
    int n = number;
    int count = 0;
    while (n) {
        count++;
        n=n&(n-1);
    }
    
    cout<<"Number of bits set in "<<number<<" are "<<count<<endl;
    
    return 0;
}
