//
//  main.cpp
//  test
//
//  Created by bsarvan on 24/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct name {
    string first;
    string last;
};

class qq {
    vector<int> s;
public:
    qq(int cap):s(cap) {}
    void print() {
        cout<<"Size of qq - "<<s.size()<<endl;
    }
};

struct name SampleFunc(){
    return {"Bharat","Sarvan"};
};

int main()
{
    
    qq obj(10);
    obj.print();
#if 0
    auto data = SampleFunc();
    cout<<"Output - "<<data.first<<" "<<data.last<<endl;
#endif
    return 0;
}


#if 0
int main(int argc, const char * argv[]) {
    list<int> l1({1,2,3,4,5,6,7,8,9});
    list<int> l2({10,20,30});
#if 0
    vector<int> A = {1,4,5,7,8,10,12};
    //vector<int> A = {1};
    vector<int> :: iterator loc;
    loc = upper_bound(A.begin(), A.end(),3);
    cout<<"Value is - "<<A[loc - A.begin()]<<endl;
#endif
    
    cout<<"Sample program to test splice function"<<endl;
    l1.splice(l1.end(), l2);
    for(auto iter = l1.begin();iter != l1.end();iter++){
        cout<<*iter<<" ";
    }
    
    string sorted_str("Bharat Sarvan");
    cout<<endl<<sorted_str<<endl;
    cout<<endl;
    return 0;
}
#endif
