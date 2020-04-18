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
    
    int carry = 0;
    string res;
    
    for (int i = A.size() - 1; i>=0;i--) {
        int n1 = A[i] - '0';
        int n2 = B[i] - '0';
        
        int val = n1^n2;
        
        int sum = val ^ carry;
        
        if (val || sum) {
            carry = 1;
        }
        
        cout<<to_string(sum)<<" ";
    }
    cout<<endl;
    return "";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string a = "101";
    string b = "001";
    addBinaryString(a, b);
    
    std::cout << "Hello, World!\n";
    return 0;
}
