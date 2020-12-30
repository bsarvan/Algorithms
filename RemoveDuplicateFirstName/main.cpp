//
//  main.cpp
//  RemoveDuplicateFirstName
//
//  Created by bsarvan on 01/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct Name {
    bool operator==(const Name &that) const {
        return first_name == that.first_name;
    }
    
    bool operator<(const Name &that) const {
        if(first_name != that.first_name) {
            return first_name < that.first_name;
        }
        return last_name < that.last_name;
    }
    
    string first_name, last_name;
};

void eliminateDuplicate(vector<Name> *A) {
  sort(A->begin(),A->end());    
  auto iter = unique(A->begin(),A->end());
  A->erase(iter, A->end());
}

void eliminateDuplicateWithReferenceArgument(vector<Name> &A) {
  sort(A.begin(),A.end());
  auto iter = unique(A.begin(),A.end());
  A.erase(iter, A.end());
}

int main(int argc, const char * argv[]) {
    cout<<"Program to remove duplicate firstnames"<<endl<<endl;
    vector<Name> names;
    names.emplace_back(Name{"Ian","Botham"});
    names.emplace_back(Name{"David","Gower"});
    names.emplace_back(Name{"Ian","Findlay"});
    names.emplace_back(Name{"Roger","Fedrer"});
    names.emplace_back(Name{"Ian","Bond"});
    names.emplace_back(Name{"David","Fedrer"});
    names.emplace_back(Name{"John","Fedrer"});
   
    cout<<"List of Names - "<<endl;
    
    for(auto c:names){
        cout<<c.first_name<<" "<<c.last_name<<endl;
    }
    cout<<endl;
    eliminateDuplicate(&names);
    
    cout<<"List of Names after filter "<<endl;
    for(auto c:names){
        cout<<c.first_name<<" "<<c.last_name<<endl;
    }
    return 0;
}
