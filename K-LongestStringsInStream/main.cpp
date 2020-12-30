//
//  main.cpp
//  K-LongestStringsInStream
//
//  Created by Bharat Sarvan on 19/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Algorithm to find K longest strings in a stream of strings

bool min_heap(string s1, string s2) {
    return s1.size() > s2.size();
}

vector<string> FindKStrings(int K, istringstream * stream) {
    priority_queue<string, vector<string>, function<bool(string, string)>> min_heap([] (const string &a, const string &b) -> bool {
        return a.size() >= b.size();
    });
    
    vector<string> result;
    string next_string;
    
    while(*stream >> next_string) {
        min_heap.emplace(next_string);
        if (min_heap.size() > K) {
            min_heap.pop();
        }
    }
    
    while(!min_heap.empty()){
        result.emplace_back(min_heap.top());
        min_heap.pop();
    }
    
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the K longest strings in a stream of strings"<<endl;
    
    string input("Bharat Rob Joy KK Tavish Amy Rupal JJ");
    
    istringstream my_stream(input);
    
    vector<string> result = FindKStrings(3, &my_stream);
    
    for(auto r:result) {
        cout<<r<<endl;
    }
    
    
    return 0;
}
