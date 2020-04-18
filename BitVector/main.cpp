//
//  main.cpp
//  BitVector
//
//  Created by bsarvan on 04/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<int> BV(10,0);
    cout<<"Setting the 33rd bit of BV"<<endl;
    int index = 34 / 32;
    cout<<"Index of BV to fetch "<<index<<endl;
    
    //Bit to set in the BV element fetched
    int bitToSet = 34 % 32;
    cout<<"Bit to set in the BV elment fetched "<<bitToSet<<endl;
    
    //Setting the bit in the BV element
    BV[index]  |= 1 << bitToSet;
    
    cout<<"Value of BV index 2 - "<<BV[index]<<endl;
    
    return 0;
}
