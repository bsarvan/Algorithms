//
//  main.cpp
//  BuySellStocksII
//
//  Created by Bharat Sarvan on 24/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Say you have an array, A, for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit.

 You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

 However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Input Format:

 The first and the only argument is an array of integer, A.
 Output Format:

 Return an integer, representing the maximum possible profit.
 Constraints:

 1 <= len(A) <= 1e5
 1 <= A[i] <= 1e7
 Example :

 Input 1:
     A = [1, 2, 3]

 Output 1:
     2

 Explanation 1:
     => Buy a stock on day 0.
     => Sell the stock on day 1. (Profit +1)
     => Buy a stock on day 1.
     => Sell the stock on day 2. (Profit +1)
     
     Overall profit = 2

 Input 2:
     A = [5, 2, 10]

 Output 2:
     8

 Explanation 2:
     => Buy a stock on day 1.
     => Sell the stock on on day 2. (Profit +8)
     
     Overall profit = 8

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int> &A);
};


int Solution::maxProfit(const vector<int> &A) {
    int total_profit = 0;
    
    if (A.size() == 0) {
        return 0;
    }
    
    int prev_min_price = A[0];
    
    for (auto &price : A) {
        if (price > prev_min_price) {
            int profit = price - prev_min_price;
            total_profit += profit;
            prev_min_price = price;
        } else {
            prev_min_price = min(prev_min_price, price);
        }
    }
    
    return total_profit;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the maximum profit"<<endl;
    
    vector<int> A = {1,2,3};
    Solution sol;
    
    int result = sol.maxProfit(A);
    cout<<"Maximum Profit is "<<result<<endl;
    return 0;
}
