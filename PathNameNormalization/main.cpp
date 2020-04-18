//
//  main.cpp
//  PathNameNormalization
//
//  Created by bsarvan on 27/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string path = "/home/bharat/../../usr/bin/gcc";


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathnames;

        if (path[0] == '/') {
            pathnames.emplace_back("/");
        }

        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')) {
            if (token == "..") {
                if (pathnames.back() != "/") {
                    pathnames.pop_back();
                }
            } else if (token != "."  && token != "") {
                pathnames.emplace_back(token);
            }
        }

        string result;

        if (!pathnames.empty()) {
            result = pathnames.front();
            for(int i = 1; i < pathnames.size(); i++) {
                if (i == 1 && result == "/") {
                    result += pathnames[i];
                } else {
                    result += "/" + pathnames[i];
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    cout<<"Input path name is "<<path<<endl;
    
    vector<string> pathnames;
    
    if (path[0] == '/') {
        pathnames.emplace_back("/");
    }
    
    stringstream ss(path);
    string token;
    while(getline(ss, token, '/')) {
        if (token == "..") {
            if (pathnames.empty() || pathnames.back() == "..") {
                pathnames.emplace_back(token);
            } else {
                if (pathnames.back() == "/") {
                    cout<<"Path Error"<<endl;
                }
                cout<<"Popping back"<<endl;
                pathnames.pop_back();
            }
        } else if (token != "." && token != "") {
            pathnames.emplace_back(token);
        }
    }
    
    for (auto s:pathnames) {
        cout<<s<<" ";
    }
    
    cout<<endl;
    
    string result;
    
    if (!pathnames.empty()) {
        result = pathnames.front();
        for(int i = 1; i < pathnames.size(); i++) {
            if (i == 1 && result == "/") {
                result += pathnames[i];
            } else {
                result += "/" + pathnames[i];
            }
        }
    }
    

    cout<<"Path - "<<result<<endl;
    
    
    Solution sol;
    
    string result2 = sol.simplifyPath(path);

    cout<<"Result2 - "<<result2<<endl;
    return 0;
}
