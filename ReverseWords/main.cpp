//
//  main.cpp
//  ReverseWords
//
//  Created by bsarvan on 03/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void reverseWords(string s){
    reverse(s.begin(),s.end());
    
    int start = 0, end;
    
    while((end = s.find(" ", start)) != string::npos) {
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
    }
    
    reverse(s.begin() + start, s.end());
    
    cout<<s<<endl;
    return;
}
int main(int argc, const char * argv[]) {
    reverseWords("I love Tavi");
    return 0;
}
