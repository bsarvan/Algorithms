//
//  main.cpp
//  ToggleBit
//
//  Created by bsarvan on 02/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    cout<<"Program to test bit toggling to count number of Odd Characters in string"<<endl;
    string S = "aabbcc";
    
    int bitVector  = 0;
    
    for (int i = 0; i < S.size(); i++ ) {
        int toggleBit = S[i] - 'a';
        int mask = 1 << toggleBit;
        bitVector ^= mask;
    }
    
    cout<<"Bit Vector is "<<bitVector<<endl;
    
    cout<<"==========================="<<endl;
    
    string a = "aa";
    string b = "ab";
    
    cout<<"Comparing results "<<b.compare(a)<<endl;
    
    
    return 0;
}
