//
//  main.cpp
//  ContactListHash
//
//  Created by bsarvan on 01/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    size_t hash_code;
    
    while(1) {
        string name;
        hash<string> hashfunc;
        cin>>name;
        hash_code = hashfunc(name);
        hash_code ^=hash_code;
        cout<<"Hash Code - "<<hash_code<<endl;
    }
    
    return 0;
}
