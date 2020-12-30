//
//  main.cpp
//  PartitionArrayEqualSum
//
//  Created by Bharat Sarvan on 20/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


size_t partitionEqualSum(vector<int> arr) {
    int leftsum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        leftsum += arr[i];
    }
    
    int rightsum = 0;
    for (size_t i = arr.size() - 1; i >= 0; i--) {
        rightsum += arr[i];
        
        leftsum -= arr[i];
        
        if (leftsum == rightsum) {
            return i;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to partition the vector in two halves with equal sum"<<endl;
    
    vector<int> arr = {1 , 2 , 3 , 4 , 5 , 5 };
    size_t result = partitionEqualSum(arr);
    
    cout<<"Vector Index - "<<result<<endl;
    
    return 0;
}
