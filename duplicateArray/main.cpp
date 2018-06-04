//
//  main.cpp
//  duplicateArray
//
//  Created by bsarvan on 14/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void printArray(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
int main(int argc, const char * argv[]) {
    //vector<int> arr = {3,2,4,2,1,5,6};
    vector<int> arr = {3,2,4,1,4,5,6};
    cout<<"Program to find the duplicate entry in array"<<endl;
    printArray(arr);
    
    int slow = arr[0];
    int fast = arr[arr[0]];
    
    while(slow != fast){
        cout<<"Slow - "<<slow<<", Fast - "<<fast<<endl;
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    cout<<"Loop Exited 1"<<endl;
    cout<<"Slow - "<<slow<<", Fast - "<<fast<<endl;
    
    fast = 0;
    while (slow != fast) {
        cout<<"Slow - "<<slow<<", Fast - "<<fast<<endl;
        slow = arr[slow];
        fast = arr[fast];
    }
    
    cout<<"Loop Exited 2"<<endl;
    cout<<"Slow - "<<slow<<", Fast - "<<fast<<endl;
    
    return 0;
    
}
