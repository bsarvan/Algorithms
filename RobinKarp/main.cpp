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

size_t RobinKarp(string s, string t) {
    if (s.size() > t.size()) {
        cout<<"Error: S cannot be a substring of t"<<endl;
        return -1;
    }
    
    const int kbase = 11;
    int t_hash = 0, s_hash = 0;
    int power_s = 1;
    
    for(int i=0;i<s.size();i++){
        power_s = i ? power_s*kbase:1;
        cout<<"Character - "<<t[i]<<", Power - "<<power_s<<", t_hash - "<<t_hash<<", kbase - "<<kbase<<endl;
        t_hash = t_hash*kbase + t[i];
        s_hash = s_hash*kbase + s[i];
    }
    
    for(size_t i=s.size();i<t.size();i++){
        cout<<"t_hash - "<<t_hash<<", s_hash - "<<s_hash<<endl;
        if ((t_hash == s_hash) && t.compare(i-s.size(),s.size(),s)) {
            cout<<"Found a match"<<endl;
            return (i-s.size());
        }
        cout<<i<<endl;
        cout<<"t[i-s.size()] - "<<t[i-s.size()]<<", power_s - "<<power_s<<", hash - "<<t[i-s.size()] * power_s<<endl;
        t_hash -= t[i-s.size()]*power_s;
        t_hash = t_hash*kbase + t[i];
    }
    
    cout<<"Here   t_hash - "<<t_hash<<", s_hash - "<<s_hash<<endl;
    if ((t_hash == s_hash) && t.compare(t.size() - s.size(),s.size(),s) == 0) {
        return (t.size()-s.size());
    }
    
    return -1;
}



int RobinKarp_v2(string T, string P) {
    if (P.size() > T.size()) {
        cout<<"Error, Search not possible"<<endl;
        return -1;
    }
    
    int prime = 11;
    int t_hash = 0;
    int p_hash = 0;
    int power = 0;
    
    for (int i = 0; i < P.size(); i++) {
        power = i ? power*prime : 1;
        t_hash = t_hash + T[i]*power;
        p_hash = p_hash + P[i]*power;
    }
    
    cout<<"Hash of Pattern - "<<p_hash<<endl;
    
    for (size_t i = P.size(); i < T.size(); i++ ){
        if ((t_hash == p_hash) && (T.compare(i - P.size(), P.size(), P) == 0)) {
            cout<<"Found a match at index  - "<<i - P.size()<<endl;
        }
        
        // Remove the first character of the window
        t_hash -= T[i-P.size()];
        // Divide the previous hash with the prime number
        t_hash /= prime;
        // Multiply the new character with last power computed.
        t_hash += (T[i] * power);
    }
    
    if ((t_hash == p_hash) && (T.compare(T.size() - P.size(), P.size(), P) == 0)) {
        cout<<"Found a match at index  - "<<T.size() - P.size()<<endl;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to test Robin Karp Algorithm"<<endl;
    size_t result = RobinKarp_v2("abadcadc","adc");
    cout<<"Substring found at index - "<<result<<endl;
    return 0;
}
