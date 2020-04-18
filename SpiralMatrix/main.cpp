//
//  main.cpp
//  SpiralMatrix
//
//  Created by bsarvan on 16/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/* This code is adopted from the solution given
 @ http://effprog.blogspot.com/2011/01/spiral-printing-of-two-dimensional.html */

#include <stdio.h>
#define R 3
#define C 6

void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
    
    /* k - starting row index
     m - ending row index
     l - starting column index
     n - ending column index
     i - iterator
     */
    
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            printf("%d ", a[k][i]);
        }
        k++;
        
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            printf("%d ", a[i][n-1]);
        }
        n--;
        
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                printf("%d ", a[m-1][i]);
            }
            m--;
        }
        
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int left=0,up=0,right=matrix[0].size()-1,down=matrix.size()-1;
        while(1)
        {
            //up
            if(left>right)
                break;
            for(int i=left;i<=right;i++)
                result.push_back(matrix[up][i]);
            up++;
            
            if (up>down)
                break;
            for(int i=up;i<=down;i++)
                result.push_back(matrix[i][right]);
            right--;
            //down
            
            if (left>right)
                break;
            for(int i=right;i>=left;i--)
                result.push_back(matrix[down][i]);
            down--;
            
            if (up>down)
                break;
            for(int i=down;i>=up;i--)
                result.push_back(matrix[i][left]);
            
            left++;
            
        }
        return result;
        
        
    }
};



/* Driver program to test above functions */
int main()
{
    int a[R][C] = { {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
    
    spiralPrint(R, C, a);
    return 0;
}
