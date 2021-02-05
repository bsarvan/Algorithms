//
//  main.cpp
//  StroboGrammatic
//
//  Created by bsarvan on 03/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> helper(int n, int length) {
        if (n == 0)
            return {""};
        
        if (n == 1)
            return {"0","1","8"};
        
        vector<string> middles = helper(n-2, length);
        vector<string> result;
        
        for (auto middle : middles) {
            if (n != length) {
                result.emplace_back("0" + middle + "0");
            }
            
            result.emplace_back("1" + middle + "1");
            result.emplace_back("8" + middle + "8");
            result.emplace_back("9" + middle + "6");
            result.emplace_back("6" + middle + "9");
            
        }
        
        return (result);
    }
    
    vector<string> findStrobogrammatic(int n) {
        
        vector<string> stroboGram = helper(n,n);
        return stroboGram;
    }
};

int main(int argc, const char * argv[]) {
   
    Solution sol;
    
    vector<string> S = sol.findStrobogrammatic(3);
    
    for(auto s:S) {
        cout<<s<<" ";
    }
    
    cout<<endl;

    return 0;
}
