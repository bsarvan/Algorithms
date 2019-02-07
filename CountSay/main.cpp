//
//  main.cpp
//  CountSay
//
//  Created by bsarvan on 26/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void countAndSay(int A) {
    string s = to_string(1);
    int cnt = 0;
    string tmp;
    
    while(A-1>0){
        //cout<<"Input String - "<<s<<endl;
        for(int i=0;i<s.length();i++){
            cnt++;
            if(i+1 >= s.length() || s[i] != s[i+1]){
                tmp = tmp + to_string(cnt) + s[i];
                //cout<<"Count - "<<cnt<<", Char - "<<s[i]<<", String - "<<tmp<<endl;
                cnt = 0;
            }
        }
        cout<<tmp<<endl;
        s = tmp;
        tmp = "";
        A--;
    }
    cout<<endl<<s<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    countAndSay(5);
    return 0;
}
