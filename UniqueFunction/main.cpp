//
//  main.cpp
//  UniqueFunction
//
//  Created by bsarvan on 04/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,3,3,4,5,5,6};
    vector<int>::iterator it;
    it = unique(v.begin(),v.end());

    v.erase(it,v.end());
    
    for(auto c:v){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
