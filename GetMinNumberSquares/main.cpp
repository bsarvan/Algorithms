//
//  main.cpp
//  GetMinNumberSquares
//
//  Created by bsarvan on 18/06/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
// A naive recursive C++ program to find minimum
// number of squares whose sum is equal to a given number
using namespace std;

// Returns count of minimum squares that sum to n
int getMinSquares(unsigned int n)
{
    // base cases
    if (n <= 3)
        return n;
    
    // getMinSquares rest of the table using recursive
    // formula
    int res = n; // Maximum squares required is n (1*1 + 1*1 + ..)
    
    // Go through all smaller numbers
    // to recursively find minimum
    for (int x = 1; x <= n; x++)
    {
        int temp = x*x;
        if (temp > n)
            break;
        else
            res = min(res, 1+getMinSquares(n - temp));
    }
    return res;
}

// Driver program
int main()
{
    cout << getMinSquares(6)<<endl;
    return 0;
}

