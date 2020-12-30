//
//  main.cpp
//  IntegerSolutions
//
//  Created by Bharat Sarvan on 06/09/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;


//list<pair<int,int>> findResult(unordered_map<int, list<pair<int, int>>> mp) {
//
//}
int main(int argc, const char * argv[]) {
    unordered_map<int, list<pair<int, int>>> mp;
    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int sum = i*i + j*j;
            mp[sum].emplace_back(make_pair(i,j));
        }
    }
    
    cout<<"Size of the map is "<<mp.size()<<endl;
    
    int count = 0;
    for (auto m:mp) {
        for (auto l:m.second) {
            count++;
            cout<<l.first<<" "<<l.second<<endl;
        }
    }
    
    cout<<count<<endl;
    return 0;
}
