//
//  main.cpp
//  SoccerStack
//
//  Created by bsarvan on 14/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        long long N,Id;
        cin>>N>>Id;
        stack<long long> s;
        s.push(Id);
        while(N--){
            char ch;
            long long pid;
            cin>>ch;
            if(ch=='P'){
                cin>>pid;
                cout<<endl;
                cout<<pid<<endl;
                s.push(pid);
            }
            else{
                long long x=s.top();
                s.pop();
                long long y=s.top();
                cout<<x<<" "<<y<<endl;
                s.push(x);
                s.push(y);
            }
        }
        cout<<"Player"<<" "<< s.top()<<endl;
    }
    return 0;
}

