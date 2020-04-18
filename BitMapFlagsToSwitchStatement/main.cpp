//
//  main.cpp
//  BitMapFlagsToSwitchStatement
//
//  Created by bsarvan on 16/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

#define one 1
#define two 1<<1
#define four 1<<2

int main() {
    
    int flag = 7;
    
    for (int i=0;i<3;i++) {
        int mask = 1<<i;
        cout<<mask<<endl;
        switch (flag & mask) {
            case one:
                cout<<"one"<<endl;
                break;
            case two:
                cout<<"two"<<endl;
                break;
            case four:
                cout<<"four"<<endl;
                break;
                
        }
    }
    return 0;
}
