//
//  main.cpp
//  GroupAnagrams
//
//  Created by bsarvan on 19/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

bool comp1(string a, string b) {
    return a<b;
}

bool comp2(char a, char b) {
    return a<b;
}

int main(int argc, const char * argv[]) {
    std::cout << "Grouping Anagrams \n";
    unordered_map<string,list<string>> M;
    vector<string> S = {"abc", "cab", "ahg", "gha","bac","rat"};
    
    for (auto c:S) {
        string key = c;
        sort(key.begin(),key.end());
        M[key].emplace_back(c);
    }
    
    for (auto c:M) {
        cout<<c.first<<" --> ";
        for (auto b:c.second) {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    
#if 0
    for(auto c:S)
        cout<<c<<endl;
    
    cout<<"Sorted list of Names - "<<endl;
    sort(S.begin(), S.end(), comparator);
    for(auto c:S)
        cout<<c<<endl;
#endif
    
    return 0;
}
