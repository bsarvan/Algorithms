//
//  main.cpp
//  FormatLicenseKey
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string licenseKeyFormatting(string S, int K) {
    
    int write_index = 0;
    string res;
    int len = 0;
    for(int i=0;i<S.size();i++) {
        if (S[i] != '-') {
            S[write_index++] = S[i];
            len++;
        }
    }
    
    S.erase(len);
    cout<<"Tmp String - "<<S<<endl;
    int cnt = 0;
    int j = S.size() - 1;
    
    while(j>=0) {
        
        if (cnt == K) {
            res.insert(res.begin(),'-');
            cnt = 0;
        } else {
            cnt++;
            res.insert(res.begin(),toupper(S[j--]));
        }
    }
    
    cout<<"String Now "<<res<<endl;
    return res;
}


int main(int argc, const char * argv[]) {
    
    cout<<"Program to format licensing key"<<endl;
    licenseKeyFormatting("5F3Z-2e-9-w", 4);
    return 0;
}
