//
//  main.cpp
//  UniqueEmails
//
//  Created by bsarvan on 15/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void processLocalName(string &localname) {
    string str;
    for (auto c:localname) {
        if (c == '.')
            continue;
        
        if (c == '+') {
            break;
        }
        str.push_back(c);
    }
    localname = str;
}

size_t numUniqueEmails(vector<string>& emails) {
    size_t pos = 0;
    unordered_set<string> R;
    
    for (int i=0; i<emails.size();i++ ) {
        string str = emails[i];
        
        if ((pos = str.find("@")) != string::npos) {
            string localname = str.substr(0, pos);
            string domain = str.substr(pos+1);
            
            processLocalName(localname);
            cout<<localname<<" "<<domain<<endl;
            R.emplace(localname + "@" + domain);
        }
    }
    return R.size();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    size_t num = numUniqueEmails(emails);
    cout<<"Number of Unique Email Address - "<<num<<endl;
    return 0;
}
