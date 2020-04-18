//
//  main.cpp
//  Sub_String
//
//  Created by bsarvan on 02/05/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isSubString(string s1, string s2) {
    string s11 = s1 +  s1;
    for (int i = 0; i < (s11.size() - s2.size() - 1); i++) {
        string r = s11.substr(i, s2.size()-1);
        cout<<r<<endl;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test substring "<<endl;
    string s1 = "abcdef";
    string s2 = "defabc";
    isSubString(s1, s2);
    return 0;
}
