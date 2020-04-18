//
//  main.cpp
//  BitArray
//
//  Created by bsarvan on 19/08/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



class BitArray {
    vector<char> Arr;
    int size
public:
    BitArray(int size):size(size) {
        Arr.resize(size);
    }
    
    void Set(int pos) {
        int index = pos % 8;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
