//
//  main.cpp
//  MinCoinsForValueN
//
//  Created by bsarvan on 19/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include <iostream>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // base case
    if (V == 0) return 0;
    
    // Initialize result
    int res = INT_MAX;
    
    // Try every coin that has smaller value than V
    for (int i=0; i<m; i++)
    {
        if (coins[i] <= V)
        {
            
            int sub_res = minCoins(coins, m, V-coins[i]);
            cout<<"Value - "<<V<<", sub_res - "<<sub_res<<endl;
            
            // Check for INT_MAX to avoid overflow and see if
            // result can minimized
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    cout<<"========================"<<endl;
    return res;
}

// Driver program to test above function
int main()
{
    int coins[] = {4, 5, 3, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
    << endl<<minCoins(coins, m, V)<<endl;
    return 0;
}
