//
//  main.cpp
//  RodCutting
//
//  Created by bsarvan on 20/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int revenue(int n, vector<int> &prices) {
    if (n==0) return 0;
    
    int max_val = -1;
    for(int i = 0; i<n;i++){
        cout<<"Computing - "<<n-i-1<<", Revenue("<<i<<")"<<endl;
        int temp = prices[n-i-1] + revenue(i, prices);
        if (temp > max_val) {
            max_val = temp;
        }
    }
    cout<<"================================"<<endl;
    return max_val;
}


int revenueDP(int n, vector<int> &prices) {
  
    vector<int> R(prices.size(),0);
    R[0] = 0;
    for(int i = 1; i<=n;i++) {
        int max_val = -1;
        for(int j = 1; j <= i; j++) {
            int temp = prices[j - 1] + R[i - j];
            if (temp > max_val) {
                max_val = temp;
            }
        }
        R[i] = max_val;
    }
    return (R[n]);
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test rod cutting problem"<<endl;
    vector<int> prices = {1,5,8,9,10};
    
    cout<<revenue(5, prices)<<endl<<endl;
    cout<<revenueDP(5, prices)<<endl<<endl;
    
    return 0;
}
