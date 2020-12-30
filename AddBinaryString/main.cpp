//
//  main.cpp
//  AddBinaryString
//
//  Created by bsarvan on 15/02/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string addBinaryString(string A, string B) {
    
    int val = 0;
    string res;
    int carry = 0;
    
    for (int i = A.size() - 1; i>=0;i--) {
        int n1 = A[i] - '0';
        int n2 = B[i] - '0';
        
        int sum = n1^n2^carry;
        cout<<"Val - "<<sum;
        res.insert(0,to_string(sum));
        
        val = n1 & n2;
        if (val || val & carry)
            carry = 1;
        else
            carry = 0;
        
        cout<<", Carry - "<<carry<<endl;
        
    }
    cout<<endl;
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string a = "101";
    string b = "001";
    string res = addBinaryString(a, b);
    
    std::cout <<res<<endl;
    return 0;
}
