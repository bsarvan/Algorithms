//
//  main.cpp
//  FibFindNhtNumber
//
//  Created by bsarvan on 03/09/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int n = 8;
    
    vector<int> F(8,0);
    
    F[0] = 0;
    F[1] = 1;
    for(int i=2;i<n;i++) {
        F[i] = F[i-1] + F[i-2];
        cout<<F[i]<<" ";
        
    }
    cout<<endl;
    
    cout<<n<<"th number is "<<F[n-1]<<endl;
    return 0;
}
