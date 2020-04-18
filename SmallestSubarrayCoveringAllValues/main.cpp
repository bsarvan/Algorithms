//
//  main.cpp
//  SmallestSubarrayCoveringAllValues
//
//  Created by bsarvan on 24/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

struct subarray {
    int start;
    int end;
    
    subarray():start(-1),end(-1){};
};


subarray findSmallestRange(vector<string> text, vector<string> queryStrings) {
    struct subarray result;
    list<int> L;
    unordered_map<string, list<int>::iterator> mp;
    
    for (auto s:queryStrings) {
        mp.emplace(s,L.end());
    }
    
    for (int i=0;i<text.size(); i++) {
        auto it = mp.find(text[i]);
        if (it != mp.end()) {
            if (it->second != L.end()) {
                cout<<"Entry exists in the list.Erasing element to update"<<endl;
                L.erase(it->second);
            }
            L.emplace_back(i);
            mp.emplace(text[i], --L.end());
        }
        
        if (L.size() == queryStrings.size()) {
            if ((result.start == -1 && result.end == -1) ||
                (i - L.front() < result.end - result.start)) {
                
                result.start = L.front();
                result.end = i;
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> text = {"apple", "grape","banana","guava","cherry","apple","apple","pomo"};
    vector<string> query_strings = {"banana", "apple"};
    
    cout<<"Code to find the smallest subarray with query strings in sequence"<<endl;
    
    cout<<"Text Strings - ";
    for(auto t:text) {
        cout<<t<<", ";
    }
    cout<<endl;
    
    struct subarray range = findSmallestRange(text, query_strings);
    
    cout<<"Start Index - "<<range.start<<", End Index - "<<range.end<<endl;
    return 0;
}
