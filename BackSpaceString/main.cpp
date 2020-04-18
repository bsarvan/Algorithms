//
//  main.cpp
//  BackSpaceString
//
//  Created by bsarvan on 11/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

 Example 1:

 Input: S = "ab#c", T = "ad#c"
 Output: true
 Explanation: Both S and T become "ac".
 Example 2:

 Input: S = "ab##", T = "c#d#"
 Output: true
 Explanation: Both S and T become "".
 Example 3:

 Input: S = "a##c", T = "#a#c"
 Output: true
 Explanation: Both S and T become "c".
 
 Example 4:

 Input: S = "a#c", T = "b"
 Output: false
 Explanation: S becomes "c" while T becomes "b".
 
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(int argc, const char * argv[]) {
    
    string a = "ab#cdefg##";
    stack<char> S;
    
    cout<<"Input String  - "<<a<<endl;
   
    int i = 0;
    
    while (i<a.size()) {
        if (a[i]!='#') {
            S.push(a[i]);
        } else if (!S.empty()) {
            S.pop();
        }
        i++;
    }
    
    string ans;
    while(!S.empty()) {
        ans.insert(ans.begin(),S.top());
        S.pop();
    }
    
    cout<<"BackSpaced String - "<<ans<<endl;
    return 0;
}
