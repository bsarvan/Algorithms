//
//  main.cpp
//  SmallestSubequenceWithDistinctCharacters
//
//  Created by Bharat Sarvan on 29/10/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


string SmallestSubsequenceWithDistinct(string S) {
    int visited = 0;
    vector<int> count(26);
    stack<int> st;
    
    for (auto c:S) {
        count[c - 'a']++;
    }
    
    for (int i = 0; i < S.size(); i++) {
        int ch = S[i] - 'a';
        
        count[ch]--;
        
        if (visited & 1<<ch) {
            continue;
        }
        
        while(!st.empty() && st.top() > ch && count[st.top()] > 0) {
            visited ^= 1 << st.top();
            st.pop();
        }
        
        visited |= 1 << ch;
        st.push(ch);
    }
    
    string result;
    
    while(!st.empty()) {
        char c = st.top() + 'a';
        result.insert(result.begin(), c);
        st.pop();
    }
    cout<<result<<endl;
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string inputString = "cbacdcbc";
    SmallestSubsequenceWithDistinct(inputString);
    return 0;
}
