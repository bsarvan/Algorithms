//
//  main.cpp
//  T9
//
//  Created by bsarvan on 10/03/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> T9 = {{NULL},{NULL},{'a','b','c'},{'d','e','f'}, {'g','h','i'}, {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v',},{'w','x','y','z'}};

vector<char> getT9Chars(char digit) {
    if (!isdigit(digit)) {
        return {};
    }
    
    int i = digit - '0';
    return(T9[i]);
}

void getValidWords(string number, int index, string partialOutput, vector<string> &results) {
   
    if (index == number.length()) {
        results.push_back(partialOutput);
        return;
    }
    
    char digit = number[index];
    vector<char> letters = getT9Chars(digit);
    
    for (auto letter:letters) {
        //cout<<"Prefix - "<<prefix<<", letter - "<<letter<<endl;
        getValidWords(number, index + 1, partialOutput + letter, results);
    }
}



int main(int argc, const char * argv[]) {
    cout<<"Test Function for Recursion"<<endl;
    vector<string> R;
    getValidWords("234", 0,"", R);
    
    for(auto c:R) {
        cout<<c<<endl;
    }
    return 0;
}
