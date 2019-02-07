//
//  main.cpp
//  BuyNSellTwice
//
//  Created by bsarvan on 25/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Program to compute max profit buying and selling share twice"<<endl;
    vector<int> prices = {12,11,13,9,12,8,14,13,15};
    vector<int> profit(prices.size(),0);
    
    int min_so_far = INT_MAX;
    int max_total_profit = 0;
    int i = 0;
    
    for (auto price : prices) {
        min_so_far = min(min_so_far, price);
        max_total_profit = max(max_total_profit, price - min_so_far);
        profit[i++] = max_total_profit;
    }
    cout<<endl;
    
    for(auto p:profit){
        cout<<p<<" ";
    }
    cout<<endl;
    
    return 0;
}
