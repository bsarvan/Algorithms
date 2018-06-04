//
//  main.cpp
//  CopyConstructor
//
//  Created by bsarvan on 29/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class HowMany {
    string name;
    static int count;
public:
    HowMany(const string &o):name(o) { count++; Print("HowMany()"); }
    ~HowMany() { count--; Print("~HowMany()"); }
    void Print(const string s ="");
    HowMany(const HowMany &h):name(h.name) {
        name +="copy";
        count++;
        Print("CopyHowMany");
    }
};

int HowMany::count = 0;

void HowMany::Print(const string s)
{
    if(s.size() != 0)
        cout<<s<<": Object Count is "<<count<<endl;
    
}

HowMany f(HowMany x){
    return x;
}

int main(int argc, const char * argv[]) {
    
    HowMany h1("h");
    
    HowMany h2 = f(h1);
    
    return 0;
}
