//
//  main.cpp
//  LengthOfLastWord
//
//  Created by bsarvan on 15/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

size_t lengthOfLastWord(string S) {
    size_t start;
    
    if ((start = S.rfind(" ")) == string::npos) {
        return 0;
    }
    size_t len = S.length()  - start;
    
    return (len - 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout<<"Length of Last Word - "<<lengthOfLastWord("Bharat Sarvan you will rock Amazon")<<endl;
    
    return 0;
}
