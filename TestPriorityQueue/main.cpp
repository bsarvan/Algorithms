//
//  main.cpp
//  TestPriorityQueue
//
//  Created by bsarvan on 29/11/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void showpq(priority_queue< pair<double,int>,vector<pair<double,int>>,greater<>> s)
{
    cout<<"Contents of Priority Queue are - "<<endl;
    priority_queue< pair<double,int>,vector<pair<double,int>> ,greater<>> qq = s;
    while(!qq.empty())
    {
        pair<double,int> tmp = qq.top();
        cout<<tmp.first<<" "<<tmp.second<<endl;
        qq.pop();
    }
    cout<<endl;
    return;
}
/*
template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, class Compare, std::greater<double>>
{
public:
    
    bool find(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};
*/


int main(int argc, const char * argv[]) {
    cout<<"Program to test Priority Queue"<<endl;
    //,vector<pair<int,int>>,greater<>> q;          //Min Heap
    //custom_priority_queue<pair<int,int>,>
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>> q;
    q.push(make_pair(0.20,2));
    q.push(make_pair(0.10,5));
    q.push(make_pair(0.50,3));
    
    showpq(q);
    cout<<"Printing the output again "<<endl;
    
    
    q.push(make_pair(0.40,3));
    showpq(q);
    return 0;
}
