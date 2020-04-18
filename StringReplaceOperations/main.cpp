//
//  main.cpp
//  StringReplaceOperations
//
//  Created by bsarvan on 11/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;




string findReplace(string S, vector<int> indexes, vector<string> src, vector<string> tgt) {
    
    vector<int> match(S.size(), -1);
    string ans;
    
    for (int i=0;i<indexes.size();i++) {
        int ix = indexes[i];
        if (S.substr(ix, src[i].size()) == src[i]) {
            match[ix] = i;
        }
    }
    
    int i = 0;
    while (i < S.size()) {
        cout<<S[i]<<endl;
        if (match[i] >= 0) {
            ans+=tgt[match[i]];
            i+=src[match[i]].size();
        } else {
            ans += S[i];
            i++;
        }
        cout<<ans<<endl;
    }
    
    return "";
}
int main(int argc, const char * argv[]) {
    
    
    vector<int> indexes = {0,2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    
    findReplace("abcd", indexes, sources, targets);
    
    return 0;
}
