//
//  main.cpp
//  recursiveMultiplication
//
//  Created by bsarvan on 15/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//


#include <iostream>
using namespace std;

int minProduct(int a,int b);

int recursive(int a,int b)
{
    if(b==0)//base case for recursion to stop
        return 0;
    else
        return a + recursive(a,b-1);//recursive case
}

int minProductHelper(int smaller, int bigger) {
    
    cout<<"smaller - "<<smaller<<", bigger - "<<bigger<<endl;
    
    if (smaller == 0){
        return 0;
    } else if (smaller == 1){
        return bigger;
    }
    
    int s = smaller >> 1;
    int side1 = minProduct(s, bigger);
    int side2 = side1;
    cout<<"Side1 - "<<side1<<endl;
    if (smaller % 2 == 1){
        cout<<"small - "<<smaller<<",s - "<<s<<", calling helper"<<endl;
        side2 = minProductHelper(smaller - s, bigger);
    }
    cout<<"Side2 - "<<side2<<endl;
    return (side1 + side2);
}
int minProduct(int a,int b){
    int smaller = a > b ? b:a;
    int bigger = a > b ? a:b;
    return minProductHelper(smaller,bigger);
}


int main(int argc, const char * argv[]) {
    cout<<"Test Program for Recursive Multiplication"<<endl;
    int result =  minProduct(5, 6);
    cout<<endl<<"Product is - "<<result<<endl;
    
    
    return 0;
}
