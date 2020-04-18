//
//  main.cpp
//  SampleOfflineData
//
//  Created by bsarvan on 18/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
#include <random>
using namespace std;


void sampleOffline(vector<int> *A_ptr, int k) {
    vector<int> & A = *A_ptr;
    default_random_engine seed((random_device())());
    
    for(int i=0; i < k; i++) {
        swap(A[i], A[uniform_int_distribution<int>{i, static_cast<int>(A.size()) - 1}(seed)]);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> V = {3,7,5,11};
    
    cout<<"Sampling offline data"<<endl;
    cout<<"Sample Input - ";
    for (auto c:V)
        cout<<c<<" ";
    
    cout<<endl;
    
    sampleOffline(&V, 2);
    cout<<"Sampled Output - ";
    for (auto c:V)
        cout<<c<<" ";
    
    cout<<endl;
    return 0;
}
