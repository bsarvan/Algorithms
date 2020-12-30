//
//  main.cpp
//  LongestPrefix
//
//  Created by bsarvan on 26/01/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/* Function to find the Longest Unique Prefix */

string uniquePrefixUtil(string str1, string str2) {
    string result;
    size_t n1 = str1.length();
    size_t n2 = str2.length();
    
    for (size_t i=0,j=0; i<n1 && j<n2; i++,j++) {
        if (str1[i] != str2[j]) {
            result.push_back(str1[i]);
            break;
        } else {
            result.push_back((str1[i]));
        }
    
    }
    
    return result;
}


/*
 So, you can pick any random string from the array and start checking its characters
 from the beginning in order to see if they can be a part of the common substring.
 */
 
string commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();
    
    // Compare str1 and str2
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        
        result += str2[j];
    }
    
    return (result);
}

// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix (vector<string> A, int n)
{
    string prefix =  A[0];
    
    for (int i=1; i<=n-1; i++)
        prefix = commonPrefixUtil(prefix, A[i]);
    
    return (prefix);
}

int main(int argc, const char * argv[]) {
    vector<string> S = {"abcd", "abd"};
    
    cout<<"Longest Prefix - "<<commonPrefix(S, S.size())<<endl;
    return 0;
}
