//
//  main.cpp
//  LongestPalindrome
//
//  Created by bsarvan on 16/02/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;



string longestPalindrome(string A) {
    int start = 0;
    int length = A.size();
    int maxLen = 1;
    
    int low = 0, high;
    
    for(int i = 1; i < length; i++){
        
        /* For extracting the palindrome of even length */
        low = i-1;
        high = i;
        cout<<"Low - "<<low<<", High - "<<high<<endl;
        /* Expand the string around ith index, and check for equality */
        while((low >= 0) && (high < length) && (A[low] == A[high])){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            cout<<"Start - "<<low<<", high - "<<high<<",maxLen - "<<maxLen<<endl;
            low--;
            high++;
        }

        /* For extracting the palindrome of odd length */
        low = i-1;
        high = i+1;
        while((low >= 0) && (high < length) && A[low] == A[high]){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            cout<<"Start - "<<low<<", high - "<<high<<",maxLen - "<<maxLen<<endl;
            low--;
            high++;
 
        }

        
 

    }
    
    string sol = "";
    
    high = start+maxLen;
    while(start != high){
        sol = sol + A[start];
        start++;
    }
    
    return sol;
}


int main(int argc, const char * argv[]) {
    std::cout << "Program to find the longest palindrome substring!\n";
    string ip_str = "aaaabaaa";
    //string ip_str = "abbaghdj";
    cout<<"Input String is - "<<ip_str<<endl;
    string pal = longestPalindrome(ip_str);
    cout<<"The Longest Palindrome String is "<<pal<<endl;
    return 0;
}
