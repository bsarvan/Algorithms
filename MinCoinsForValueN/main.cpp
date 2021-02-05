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
#include <vector>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
    // base case
    if (V == 0) return 0;
    
    // Initialize result
    int res = INT_MAX;
    
    for (int i=0; i<m; i++)
    {
        if (coins[i] <= V)
        {
            int sub_res = minCoins(coins, m, V-coins[i]);
            
            // Check for INT_MAX to avoid overflow and see if
            // result can minimized
            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}



void minCoins_v2(vector<int> coins , int V, int count, int &minCount) {
    if (V == 0) {
        if (count < minCount) {
            minCount = count;
        }
        return;
    }
    
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= V) {
            minCoins_v2(coins, V - coins[i], count + 1, minCount);
        }
    }
}

// DP Approach

int minCoinsDP(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
  
    // Base case (If given value V is 0)
    table[0] = 0;
  
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
  
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}
// Driver program to test above function
int main()
{
//    int coins[] = {4, 5, 3, 1};
    int coins[] = {1,2,3,4};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 5;
    cout << "Minimum coins required is "<<minCoins(coins, m, V)<<endl;
    
    
    vector<int> input = {1,2,3,4};
    int minCount = INT_MAX;
    int count = 0;
    int val = 5;
    minCoins_v2(input, val, count, minCount);
    cout<<"MinCoins Required are - "<<minCount<<endl;
    return 0;
}
