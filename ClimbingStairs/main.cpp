//
//  main.cpp
//  ClimbingStairs
//
//  Created by bsarvan on 11/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int i = 0;
    int n = 3;
    
    int *S = new int[n+1];
    S[1] = 1;
    S[2] = 2;
    
    for(i = 3; i<=n;i++) {
        S[i] = S[i-1] + S[i-2];
    }
    
    cout<<"Number of possible ways to climb "<<n<<" stairs - "<<S[n]<<endl<<endl;
    return 0;
}
