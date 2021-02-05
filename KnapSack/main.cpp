//
//  main.cpp
//  KnapSack
//
//  Created by bsarvan on 01/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// R[i][j] is the maximum possible value by selecting the packages in [1,2,3...., i] with weight limit j

int KnapSack(int n, int w, vector<int> V, vector<int> W) {
    vector<vector<int>> R(n + 1, vector<int> (w+1, 0));
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++) {
            if ((j - W[i - 1] >= 0) && ((V[i-1] + R[i - 1][j - W[i - 1]]) > R[i-1][j])) {
                R[i][j] = V[i-1] + R[i - 1][j - W[i - 1]];
            } else {
                R[i][j] = R[i-1][j];
            }
        }
    }
    
    return (R[n][w]);
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to solve KnapSack problem"<<endl;
    
    vector<int> weights = {5,4,6,3};
    vector<int> values = {10,40,30,50};
    
    int result = KnapSack(4,9,values,weights);
    
    cout<<"Value is "<<result<<endl;
    
    return 0;
}
