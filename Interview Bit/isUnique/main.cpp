//
//  main.cpp
//  isUnique
//
//  Created by bsarvan on 28/12/17.
//  Copyright © 2017 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isUnique(string s){
    int checker = 0;
    for(int i=0;i<s.length();i++){
        int val = s[i] - 'a';
        if((checker & (1 << val)) > 0){
            return false;
        }
        checker |=1<<val;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cout<<"Program to test Unique Characters in the String"<<endl;
    if (isUnique("abcddefg"))
        cout<<"Characters in string are Unique"<<endl;
    else
        cout<<"Not Unique"<<endl;
    
    return 0;
}
