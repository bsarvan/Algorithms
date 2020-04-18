//
//  main.cpp
//  sizeofTest.cpp
//
//  Created by bsarvan on 25/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

void func(void *a, size_t *b) {
    *(int *)a = 0;
    *b = (size_t)sizeof(int);
    return;
}

int main() {
    int x,y;
    cout<<"x - "<<&x<<", y - %p"<<&y<<endl;
    func((void *)&x, &y);
    
    cout<<"x - %p"<<&x<<" - %d"<<x<<endl;
    return 0;
}

