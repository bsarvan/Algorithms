//
//  main.cpp
//  MinWindowString
//
//  Created by bsarvan on 19/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    if (s.size() == 0 || t.size() == 0) return "";
    vector<int> remaining(128, 0);
    size_t required = t.size();
    for (int i = 0; i < required; i++) remaining[t[i]]++;
    // left is the start index of the min-length substring ever found
    int min = INT_MAX, start = 0, left = 0, i = 0;
    while(i <= s.size() && start < s.size()) {
        if(required) {
            if (i == s.size()) break;
            remaining[s[i]]--;
            if (remaining[s[i]] >= 0) required--;
            i++;
            cout<<i<<endl;
        } else {
            if (i - start < min) {
                min = i -start;
                left = start;
            }
            remaining[s[start]]++;
            if (remaining[s[start]] > 0) required++;
            start++;
            cout<<"Start - "<<start<<endl;
        }
    }
    return min == INT_MAX? "" : s.substr(left, min);
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find minimum window sub string to contain all letters of string"<<endl;
    string result = minWindow("ADOBECADEBANC", "ABC");
    cout<<"Result - "<<result<<endl<<endl;
    return 0;
}
