//
//  main.cpp
//  RealToBinary
//
//  Created by bsarvan on 08/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void printBinary(double num){
    if (num >= 1 || num <= 0){
        cout<<"Returning here"<<endl;
        return;
    }
    vector<int> dec;
    while (num > 0) {
        double r = num * 2;
        
        if ( r >= 1){
            dec.emplace_back(1);
            num = r - 1;
        } else {
            dec.emplace_back(0);
            num = r;
        }
    }
    
    cout<<"Decimal number in Binary representation is - "<<endl;
    for(int i=0;i<dec.size();i++){
        cout<<dec[i];
    }
    
    cout<<endl;
    return;
}
int main(int argc, const char * argv[]) {
    cout<<"Program to represent Decimal Number to its Binary form"<<endl;
    double n = 0.625;
    printBinary(n);
    return 0;
}
