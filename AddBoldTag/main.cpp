//
//  main.cpp
//  AddBoldTag
//
//  Created by bsarvan on 17/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/*
 Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
 
 Example 1:
 Input:
 s = "abcxyz123"
 dict = ["abc","123"]
 Output:
 "<b>abc</b>xyz<b>123</b>"
 
 
 
 
 Example 2:
 Input:
 s = "aaabbcc"
 dict = ["aaa","aab","bc"]
 Output:
 "<b>aaabbc</b>c"
 
 */
#include <iostream>
#include <vector>
using namespace std;

string addBoldTag(string s, vector<string>& dict) {
    vector<bool> bold(s.size(), 0);
    if (dict.empty() || s.empty()) return s;
    
    vector<int> tagged(s.size() + 1, 0);
    for (string pat: dict) {
        size_t begin = 0;
        cout<<"Finding pattern - "<<pat<<endl;
        while (begin < s.size()) {
            begin = s.find(pat, begin);
            if (begin == string::npos) break;
            cout<<"Found pattern - "<<begin<<endl;
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
    vector<string> dict = {"abc","xyz"};
    string result = addBoldTag(A, dict);
    
    cout<<"Result - "<<result<<endl<<endl;
    return 0;
}
