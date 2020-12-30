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

subarray findSmallestSequentially(vector<string> para, vector<string> keywords) {
    
    unordered_map<string, int> keywords_to_index;
    
    for (int i = 0; i < keywords.size(); i++) {
        keywords_to_index[keywords[i]] = i;
    }
    
    vector<int> latest_occurance(keywords.size(), - 1);
    vector<int> shortest_subarray_length(keywords.size(), INT_MAX);
    
    int shortest_distance = INT_MAX;
    subarray result = subarray(-1,-1);
    
    for (int i = 0; i < para.size(); i++) {
        if (keywords_to_index.count(para[i])) {
            int keyword_idx = keywords_to_index.find(para[i])->second;
            if (keyword_idx == 0) {
                shortest_subarray_length[keyword_idx] = 1;
            } else if (shortest_subarray_length[keyword_idx - 1] != INT_MAX) {
                int distance_to_previous_keyword = i - latest_occurance[keyword_idx - 1];
                shortest_subarray_length[keyword_idx] = distance_to_previous_keyword + shortest_subarray_length[keyword_idx - 1];
            }
            latest_occurance[keyword_idx] = i;
            
            if (keyword_idx == keywords.size() - 1 &&
                shortest_subarray_length.back() < shortest_distance) {
                shortest_distance = shortest_subarray_length.back();
                result = {i - shortest_subarray_length.back() + 1, i};
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
