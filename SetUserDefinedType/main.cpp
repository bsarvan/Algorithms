//
//  main.cpp
//  SetUserDefinedType
//
//  Created by bsarvan on 26/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

struct Test {
    int x, y;
    int distance;
    
    Test(int x, int y, int T):x(x), y(y), distance(T) {}
    
    bool operator<(const Test &b) const {
        return (this->distance < b.distance);
    }
};



int main(int argc, const char * argv[]) {
    set<struct Test> S;
    
    S.insert(Test(0,1,10));
    S.insert(Test(1,0, 20));
    
    set<struct Test> :: iterator it;
    
    for (it = S.begin(); it != S.end(); it++) {
        cout<<it->x<<" "<<it->y<<" "<<it->distance<<endl;
    }
    return 0;
}
