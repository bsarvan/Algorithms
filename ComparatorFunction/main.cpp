//
//  main.cpp
//  ComparatorFunction
//
//  Created by bsarvan on 10/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Name {
    string first_name, last_name;
public:
    Name(string f, string l):first_name(f), last_name(l) {}
    bool operator==(const Name & that) const {
        return first_name ==  that.first_name;
    }
    
    bool operator<(const Name &that) const {
        if (first_name == that.first_name) {
            return (last_name < that.last_name);
        }
        return (first_name < that.first_name);
    }

    void print() {
        cout<<first_name<<" "<<last_name<<endl;
    }
};


int main(int argc, const char * argv[]) {
    
    cout<<"Program to test comparator function in sorting"<<endl;
    
    //vector<string> S = {"Zeoon", "Bharat", "Tavish", "Rupal"};
    vector<Name> V;
    
    V.emplace_back("Ian","Botham");
    V.emplace_back("David","Gover");
    V.emplace_back("Ian","Chappel");
    V.emplace_back("David","Rwan");
    V.emplace_back("Ian","Bell");
    
    
   // for (auto c:S){
   //     cout<<c<<" ";
   // }
    cout<<endl;
    
    sort(V.begin(),V.end());
    
    for(auto b:V){
        b.print();
    }
    cout<<endl;
    
    return 0;
}
