//
//  main.cpp
//  AddTwoStrings
//
//  Created by Bharat Sarvan on 06/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//


/*
 Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

 Note:

 The length of both num1 and num2 is < 5100.
 Both num1 and num2 contains only digits 0-9.
 Both num1 and num2 does not contain any leading zero.
 You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        if (num1.size() > num2.size()) {
            swap(num1, num2);
        }
        
        if (num1.size() < num2.size())  {
            int fillsize = num2.size() - num1.size();
            while(fillsize--) {
                num1.insert(0, "0");
            }
        }
            
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        int value = 0;
        string sum;
        
        while(i >= 0 || j >= 0 ) {
            int m = num1[i] - '0';
            int n = num2[j] - '0';
            
            value = (m + n + carry) % 10;
            carry = (m + n + carry) / 10;
            sum += '0' + value;
            i--;
            j--;
        }
        
        if (carry) {
            sum += '0' + 1;
        }
        
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Algorithm to add two strings with non-negative integers"<<endl;
    
    string a = "99";
    string b = "9";
    
    Solution sol;
    string result = sol.addStrings(a, b);
    
    cout<<"Sum = "<<result<<endl;
    
    return 0;
}
