//
//  main.cpp
//  StringConversion
//
//  Created by bsarvan on 03/05/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;

int StringInt(string s)
{
    int is_negative = s[0] == '-'? 1:0;
    int digit, result;
    
    for ( int i = s[0] == '-'?1:0;i<s.size();i++){
        digit = s[i] - '0';
        result = result * 10 + digit;
    }
    return is_negative? -result:result;
}

void IntToString(int n)
{
    int ar[10];
    int digit, i=0;
    
    while(n)
    {
        digit = n%10;
        ar[i++] = digit;
        n = n / 10;
        cout<<"Digit - "<<digit<<",n - "<<n<<endl;
    }
    for(int l=0;l<i;l++)
        cout<<ar[l]<<" ";
    
    cout<<endl;
    return;
    
}


void IntToStr(int n){
    bool is_neg = false;
    if(n<0){
        n=-n;
        is_neg = true;
    }
    
    string s;
    
    do {
        s +='0' + n%10;
        n /=10;
    } while(n);
    
    if(is_neg)
        s+='-';
    
    reverse(s.begin(),s.end());
    
    cout<<s<<endl;
}


long reverseDigit(int x){
    bool is_negative = x < 0;
    int result = 0, x_remaining = abs(x);
    while(x_remaining) {
        result = result * 10 + x_remaining % 10;
        x_remaining /=10;
    }
    
    return is_negative? -result:result;
}


int main()
{
    string str = "314";
    cout<<"Test program to convert string to int"<<endl;
    //cout<<StringInt(str)<<endl;
    //IntToStr(314);
    
    cout<<"Result of digit 87867 is "<<reverseDigit(87867)<<endl;
    return 0;
}

