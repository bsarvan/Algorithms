//
//  main.cpp
//  SubsequenceOfString
//
//  Created by bsarvan on 13/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

/*
 Implement a function that prints all possible combinations of the characters in a string.
 These combinations range in length from one to the length of the string. Two combinations
 that differ only in ordering of their characters are the same combination.
 In other words, “12” and “31” are different combinations from the input string “123”, but “21” is the same as “12”.
 */


#include <iostream>
#include <string>
using namespace std;

void powerSet(string S, int index = 0, string curr = "") {
    
    //int n = S.length();
    
    // Print the output string
    cout << curr << "\n";
    
    
    if (index == S.size()) {
        cout<<"Returning here at full - "<<curr<<endl;
        return;
    }
    
    
    for(int i = index; i<S.size(); i++) {
        // Append every letter in the string S, to output string curr
        curr +=S[i];
        // Recursively call the generator function, with the input start position
        // set to the next letter after the one that is just selected.
        // (i + 1) indicates next index.
        powerSet(S,i + 1,curr);
        // After returning from the recursive function, delete the character just appended
        // to make room for the next character.
        curr.erase(curr.size() - 1);
        
    }
    
    cout<<"Returning at the end"<<endl;
    return;
}




void recursive(string S, int index=-1, string curr = "") {
    int n = S.length();
    
    if (index == n) {
        cout<<"Returning"<<endl;
        return;
    }
    
    cout<<curr<<endl;
    
    for (int i = index+1; i < n; i++) {
        curr+=S[i];
        recursive(S,i,curr);
        curr.erase(curr.size() - 1);
        cout<<"=================="<<endl;
    }
    
    cout<<"Returing here at end"<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to find the subsequence of string"<<endl;
    string str = "abc";
    powerSet(str);
    //recursive(str);
    return 0;
}
