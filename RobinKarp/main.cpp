//
//  main.cpp
//  RobinKarp
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int RobinKarp(string s, string t) {
    if (s.size() > t.size()) {
        cout<<"Error: S cannot be a substring of t"<<endl;
        return -1;
    }
    
    const int kbase = 26;
    int t_hash, s_hash = 0;
    int power_s = 1;
    
    for(int i=0;i<s.size();i++){
        power_s = i ? power_s*kbase:1;
        cout<<"Power - "<<power_s<<endl;
        t_hash = t_hash*kbase + t[i];
        s_hash = s_hash*kbase + s[i];
    }
    
    for(int i=s.size();i<t.size();i++){
        cout<<"t_hash - "<<t_hash<<", s_hash - "<<s_hash<<endl;
        if ((t_hash == s_hash) && t.compare(i-s.size(),s.size(),s)) {
            cout<<"Found a match"<<endl;
            return (i-s.size());
        }
        cout<<"i - "<<i<<endl;
        cout<<"t[i-s.size()] - "<<t[i-s.size()]<<endl;
        t_hash -= t[i-s.size()] * power_s;
        
        t_hash = t_hash*kbase + t[i];
    }
    
    cout<<"Here   t_hash - "<<t_hash<<", s_hash - "<<s_hash<<endl;
    if ((t_hash == s_hash) && t.compare(t.size() - s.size(),s.size(),s) == 0) {
        return (t.size()-s.size());
    }
    
    return -1;
}



int main(int argc, const char * argv[]) {
    cout<<"Program to test Robin Karp Algorithm"<<endl;
    int result = RobinKarp("babc", "abaacbabc");
    cout<<"Result of Substring Search - "<<result<<endl;
    return 0;
}
