//
//  main.cpp
//  unordered_set
//
//  Created by bsarvan on 13/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;

int main ()
{

    std::unordered_set<std::string> myset =
    {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
    
    std::cout << "myset contains:";
    for ( auto it = myset.begin(); it != myset.end(); ++it )
        std::cout << " " << *it;
    std::cout << std::endl;
    
    std::cout << "myset's buckets contain:\n";
    for ( unsigned i = 0; i < myset.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:";
        for ( auto local_it = myset.begin(i); local_it!= myset.end(i); ++local_it )
            std::cout << " " << *local_it;
        std::cout << std::endl;
    }
    
    unordered_set<string>::iterator it;
    it = myset.find("Venus");
    
    cout<<"Bharat - "<<*it<<endl;
    

#if 0
    cout<<"Program to test unordered_map"<<endl;
    unordered_map<int,list<int>> mp;
    
    list<int> ll;
    ll.emplace_back(1);
    ll.emplace_back(2);
    ll.emplace_back(3);
    mp.emplace(1,ll);
    
    unordered_map<int, list<int>>::iterator iter;
    for(iter=mp.begin();iter != mp.end();iter++) {
        for(auto c:iter->second){
            cout<<c<<" ";
        }
    }
#endif
    
    cout<<endl;
    return 0;
}
