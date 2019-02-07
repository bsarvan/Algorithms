//
//  main.cpp
//  Tinybool
//
//  Created by bsarvan on 13/06/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

typedef signed char tinybool;

struct abc {
    tinybool flag :1;
};


int main(int argc, const char * argv[]) {
    cout<<"Sample program to test tinybool variable assignment"<<endl;
    
    struct abc a;
    a.flag = 1;
    printf("%d\n", a.flag);
    if (a.flag == 1){
        cout<<"TRUE"<<endl;
    }

    return 0;
}

