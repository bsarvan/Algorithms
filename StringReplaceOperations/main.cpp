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
        
        // Check if the index is match to be replaced
        if (match[i] >= 0) {
            // Append the target pattern to the result
            ans+=tgt[match[i]];
            // Move the index by the length of the replaced pattern
            i+=src[match[i]].size();
        } else {
            // For index not to be replaced, add the character to the result string
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
