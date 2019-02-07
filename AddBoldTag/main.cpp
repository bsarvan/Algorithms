//
//  main.cpp
//  AddBoldTag
//
//  Created by bsarvan on 17/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string addBoldTag(string s, vector<string>& dict) {
    vector<bool> bold(s.size(), 0);
    if (dict.empty() || s.empty()) return s;
    
    vector<int> tagged(s.size() + 1, 0);
    for (string pat: dict) {
        size_t begin = 0;
        while (begin < s.size()) {
            begin = s.find(pat, begin);
            if (begin == string::npos) break;
            fill(tagged.begin() + begin, tagged.begin() + begin + pat.size(), 1);
            begin ++;
        }
    }
    string res = "";
    
    for (auto c:tagged){
        cout<<c<<" ";
    }
    cout<<endl;
    
    for (size_t i = 0; i <= s.size(); i++) {
        if (i == 0) {
            if (tagged[i] == 1) res += "<b>";
        }
        else {
            if (tagged[i] == 1 && tagged[i - 1] == 0) res += "<b>";
            if (tagged[i] == 0 && tagged[i - 1] == 1) res += "</b>";
        }
        
        if (i < s.size()) res += s[i];
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to add bold tag to string"<<endl;
    string A = "abcxyz123";
    vector<string> dict = {"abc","123"};
    string result = addBoldTag(A, dict);
    
    cout<<"Result - "<<result<<endl<<endl;
    return 0;
}
