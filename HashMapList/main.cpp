//
//  main.cpp
//  HashMapList
//
//  Created by bsarvan on 09/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include<iostream>
#include<list>
#include<map>

using namespace std;

int main(int argc, const char * argv[]) {
    list<int> ll;
    map<int, list<int> > hash;
    map<string, list<string> > stringhash;
    list<string> k;
    
    k.emplace_back("Bharat");
    k.emplace_back("Sarvan");
    
    cout<<"Program to test Hash Map List"<<endl;
    int n = 10;
    while(n-->0){
        hash[10].push_back(n);
    }
    
    for (auto a:hash[10]){
        cout<<a<<" ";
    }
    cout<<endl;
    string e="B";
    stringhash.insert(pair<string,list<string>>(e,k));
    
    for(auto val:stringhash[e]){
        cout<<val<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
