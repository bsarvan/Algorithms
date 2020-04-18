//
//  main.cpp
//  FlipXY
//
//  Created by bsarvan on 09/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    
    string S = "xyxxyyxyyx";
    
    for (int i=1;i<S.size();i++) {
        
        if (S[i] == 'x' && S[i-1] == 'y') {
            cout<<"Flip"<<endl;
        }
    }
    
    return 0;
}
