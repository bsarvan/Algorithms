//
//  main.cpp
//  plusOne
//
//  Created by bsarvan on 18/03/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


vector<int> plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    int plus = 1;
    int carry = 1;
    
    
    int l=0;
    if (n>1) {
        while(A[l] == 0) {
            l++;
        }
        A.erase(A.begin(), A.begin()+l);
    }
    
    std::reverse(A.begin(), A.end());
    
    for(int i=0;i<n;i++){
        int sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry){
        A.push_back(carry);
    }
    
    std::reverse(A.begin(),A.end());
    return A;
    
}


vector<int> plusone1(vector<int> a)
{
    ++a.back();
    for(int i=a.size()-1;i>0 && a[i] == 10; i--){
        cout<<"Here "<<a[i]<<endl;
        a[i] = 0;
        ++a[i-1];
    }
    
    if (a[0] == 10){
        a[0] = 0;
        a.insert(a.begin(), 1);
    }
    return(a);
}


int main(int argc, const char * argv[]) {
    cout<<"Program to test array plus one"<<endl;
    vector<int> arr = {0,0,1,8,9};
    
    vector<int> res;
    
    //res = plusOne(arr);
    res = plusone1(arr);
    
    for (auto a=res.begin();a < res.end();a++)
    {
        cout<<*a;
    }
    cout<<endl;
    return 0;

}
