//
//  main.cpp
//  GenerateRandomNumNotInList
//
//  Created by bsarvan on 05/09/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//


/*
 Given an integer n and a list of integers l, write a function that randomly generates a number from 0 to n-1 that isn't in l (uniform).
 
 
Solution -
 
 One way we can approach this problem is by using rejection sampling. First, we generate a (uniformly) random integer between 0 and n-1 (inclusive). Then, we check whether the random integer is found within the list l. If it is found, then generate repeat the process. If it is not found, then return that number. To make sure we can check for the presence of a number in O(1) time, we can put all integers in l in a set.
 
 Since this solution involves repeatedly generating a new random number, it could have up to infinite worst-case runtime. The initial call also incurs O(N) to convert list into a set. The probability of selecting a random number depends on the the ratio of numbers in l that are within the bounds 0 to n-1, versus the number n.
 
 Another way we can approach this problem is by generating a random number strictly from the numbers available. We can construct the list of numbers of available by subtracting the set of integers in l from the set of integers in the range 0 to n-1. Then, we can simply generate a random number within 0 and the length of this new list, and return the integer at that index.
 
 This solution takes O(N) time to pre-process the list, and O(1) time to generate a random integer.
 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


void printArray(vector<int> V) {
    for(auto c:V){
        cout<<c<<" ";
    }
    cout<<endl;
    return;
}

vector<int> buildList(int n, set<int> L) {
    vector<int> list;
    
    for(int i=0;i<n;i++) {
        if (L.find(i)==L.end()) {
            list.emplace_back(i);
        }
    }
    
    printArray(list);
    return (list);
    
}



int main(int argc, const char * argv[]) {
    vector<int> L = {5,1,3,4,8,10,15,20,11,13,8,10,14};
    set<int> S;
    for(auto c:L){
        S.emplace(c);
    }
    
    int N = 20;
    
    vector<int> mask = buildList(N,S);
    /* initialize random seed: */
    srand((unsigned)time(NULL));
    int r = rand()%mask.size();
    
    cout<<"Random Number not in List - "<<r<<", "<<mask[r]<<endl;

    return 0;
}
