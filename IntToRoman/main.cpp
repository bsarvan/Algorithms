//
//  main.cpp
//  IntToRoman
//
//  Created by bsarvan on 05/02/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

string intToRoman(int num) {
    // 1000, 2000, 3000
    string M[] = {"", "M", "MM", "MMM"};
    // 100, 200, 300, .. 900
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    // 10, 20, ... 90
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    // 1, 2, ... 9
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

int main(int argc, const char * argv[]) {
    
    cout<<"300 in Roman is - "<<intToRoman(300)<<endl;
    
    return 0;
}
