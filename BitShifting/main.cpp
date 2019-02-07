//
//  main.cpp
//  BitShifting
//
//  Created by bsarvan on 08/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

int repeatedArithmeticShift(int number, int count) {
    for(int i=0;i<count;i++){
        number = number >>> 1;
    }
    return number;
}

int repeatedLogicalShift(int number, int count){
    for(int j=0;j<count; j++){
        number>>=1;
    }
    return number;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to check the difference between Arithmetic and Logical Shifting"<<endl;
    
    int arithShift = repeatedArithmeticShift(-93242, 40);
    int logShift = repeatedLogicalShift(-93242, 40);
    
    cout<<"Arithmetic Shift Result - "<<arithShift<<" , Logical Shift Result - "<<logShift<<endl;
    
    return 0;
}
