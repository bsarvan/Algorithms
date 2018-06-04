//
//  main.cpp
//  sherlock
//
//  Created by bsarvan on 05/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> a, int l, int h)
{
    int sum = 0;
    while(l<=h){
        sum +=a[l];
        l++;
    }
    return sum;
}


string solve(

int main(int argc, const char * argv[]) {
    cout<<"Puzzle"<<endl;
    
    //vector<int> arr = {1,2,3,3};
    vector<int> arr = {3,3,1,2};
    int len = arr.size();
    int low = 0, high = len - 1;
    bool flag = false;
    
    for (int mid = 1;mid<high;mid++)
    {
        int sum1 = sum(arr, low, mid - 1);
        int sum2 = sum(arr, mid + 1, high);
        cout<<"sum1 - "<<sum1<<", sum2 - "<<sum2<<endl;
        if ((sum1 == arr[mid]) &&
            (sum2 == arr[mid])) {
            flag = true;
        }
    }
    
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}
