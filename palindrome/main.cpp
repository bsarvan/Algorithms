//
//  main.cpp
//  palindrome
//
//  Created by bsarvan on 30/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;



/*
 
 You are given a string. The only operation allowed is to insert characters in the beginning of the string.
 How many minimum characters are needed to be inserted to make the string a palindrome string
 
 Example:
 Input: ABC
 Output: 2
 Input: AACECAAAA
 Output: 2
 
 */

int solve(string A) {
    int n = A.size(), match = 1;
    
    if(n == 0){
        return 0;
    }
    
    for(int i = 1; i < n; i++){
        int start = 0, end = i, pal = 1;
        cout<<"Start - "<<start<<". End - "<<end<<endl;
        while(start < end){
            cout<<"A[start] - "<<A[start]<<",A[end] - "<<A[end]<<endl;
            if(A[start] != A[end]){
                pal = 0;
                break;
            }
            start++;
            end--;
        }
        
        if(pal){
            cout<<"Incrementing match by "<<i<<endl;
            match = i + 1;
        }
    }
    cout<<"Match - "<<match<<endl;
    cout<<"n     - "<<n<<endl;
    return n - match;
}


int findMinimumCharactersToAddAtBeginforPalindrome(string A) {
    int start = 0 , end = A.length()-1;
    int temp_end = end;
    /*Idea is to find longest palindrome length starting from index 0 . Differece of
     this length from string length is the required value*/
    while(start<=temp_end)
    {
        if(A[start]==A[temp_end])
        {
            start++;
            temp_end--;
        } else {
            start = 0;
            temp_end = --end;
        }
    }
    return A.length()-(end+1);
}


size_t findMinimumCharactersToAddAtEndforPalindrome(string A) {
    size_t start = 0 , end = A.length()-1;
    size_t temp_start = start;
    /*Idea is to find longest palindrome length starting from index 0 . Differece of
     this length from string length is the required value*/
    while(temp_start<=end)
    {
        if(A[temp_start]==A[end])
        {
            temp_start++;
            end--;
        }
        else
        {
            end = A.length() - 1;
            temp_start = start++;
        }
    }
    return start - 1;
}

int main(int argc, const char * argv[]) {
    cout<<"Program to find minimum characters to make the string palindrome"<<endl;
    //int num = solve("AACECAAAA");
    int num2 = findMinimumCharactersToAddAtBeginforPalindrome("AACECAAAA");
    size_t num3 = findMinimumCharactersToAddAtEndforPalindrome("AAACAB");
    cout<<"Number of characters needed to insert before the string to make it palindrom - "<<num2<<endl;
    cout<<"Number of characters to append at the end of the string to make it palindrome - "<<num3<<endl;
    return 0;
}
