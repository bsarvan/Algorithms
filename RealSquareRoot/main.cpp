//
//  main.cpp
//  RealSquareRoot
//
//  Created by bsarvan on 10/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


#include <iostream>
using namespace std;


int myModifiedSqrt(int x) {
    if(x<=1) return x;
    int lo = 1;
    int hi = x;
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if(mid <= x/mid)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return hi;
}

int mySqrt(int x) {
    
    if (x <= 1) {
        return x;
    }
    
    int left = 1;
    int right = x;
    int mid = 0;
    
    while(left<right) {
        mid = left + (right-left)/2;
        int mid_squared = mid*mid;
        
        if (mid_squared == x) {
            return (mid);
        } else if (mid_squared > x) {
            right = mid-1;
        } else {
            left = mid+1;
        }
        
    }
    return left - 1;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to compute Square Root"<<endl;
    
    cout<<"Square Root is "<<myModifiedSqrt(8)<<endl<<endl;
    cout<<"Square Root is "<<mySqrt(8)<<endl<<endl;
    
    return 0;
}
