//
//  main.cpp
//  StringToInt
//
//  Created by Bharat Sarvan on 17/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    long long int myAtoi(string str) {

        string tmp;
        long long result = 0;
        
        if (str.empty())
            return 0;
        
        if (isalpha(str[0]))
            return 0;
        
        if (str[0] == '-' || str[0] == '+') {
            if (!isdigit(str[1])) {
                return 0;
            }
        }
        
        //Trim the initial white spaces
        int idx = 0;
        while(idx < str.size() && isspace(str[idx])) {
            idx++;
        }
        
        str.erase(str.begin(), str.begin() + idx);
        
        cout<<str<<endl;
        
        for (int i = 0; i<str.size(); i++) {
            
            if (str[i] == '.') {
                cout<<"Breaking"<<endl;
                break;
            }
            
            if (isspace(str[i])) {
                cout<<"Space"<<endl;
                return 0;
            }
            
            if (i != 0 && !isdigit(str[i])) {
                break;
            }
            
            //if (str[i] == '-' || isdigit(str[i])) {
                tmp += str[i];
            //}
        }

        for (int i = tmp[0]=='-' || tmp[0] == '+'? 1:0;i<tmp.size();i++) {
            long long digit = tmp[i] - '0';
            result = result*10 + digit;
        }
        
        
        if (tmp[0] == '-') result = -result;
        
        if (result < INT_MIN) return INT_MIN;
        
        if (result > INT_MAX) return INT_MAX;
        
        return result;
    }
};


int main() {
    Solution sol;
    
    string input = "   +0 123";
    long long int result = sol.myAtoi(input);
    cout<<result<<endl;
    
    return 0;
}
