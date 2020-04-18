//
//  main.cpp
//  LRUCache_LeetCode
//
//  Created by bsarvan on 20/01/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> l;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        else{
            l.erase(m[key].second);
            l.push_front(key);
            m[key].second = l.begin();
            return m[key].first;
        }
    }
    
    void put(int key, int value) {
        if (m.count(key) == 0) {
            if (l.size() == cap) {
                int last = l.back();
                l.pop_back();
                m.erase(last);
            }
        } else {
            l.erase(m[key].second);
        }
        
        l.push_front(key);
        m[key] = {value, l.begin()};
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
