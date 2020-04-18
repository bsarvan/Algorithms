//
//  main.cpp
//  CharFrequencyTable
//
//  Created by bsarvan on 18/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void BuildFreqTable(unordered_map<char,int> &FreqTable, string s) {
    for (int i = 0; i<s.size(); i++) {
        FreqTable[s[i]]++;
    }
    return;
}
int main(int argc, const char * argv[]) {
    unordered_map<char, int> Table;
    string S = "elephant";
    
    BuildFreqTable(Table, S);
    
    for(auto c:Table) {
        cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}
