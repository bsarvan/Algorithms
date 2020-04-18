//
//  main.cpp
//  LongestSubstringWithKDistinct
//
//  Created by bsarvan on 14/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

// C++ program to find the longest substring with k unique
// characters in a given string
#include <iostream>
#include <cstring>
#define MAX_CHARS 26
using namespace std;



/*
Given a string you need to print longest possible substring that has exactly M unique characters.
If there are more than one substring of longest possible length, then print any one of them.

Examples -
 "aabbcc", k = 1
 Max substring can be any one from {"aa" , "bb" , "cc"}.
 
 "aabbcc", k = 2
 Max substring can be any one from {"aabb" , "bbcc"}.
 
 "aabbcc", k = 3
 There are substrings with exactly 3 unique characters
 {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
 Max is "aabbcc" with length 6.
 
 "aaabbb", k = 3
 There are only two unique characters, thus show error message.
 
 */

// This function calculates number of unique characters
// using a associative array count[]. Returns true if
// no. of characters are less than required else returns
// false.
bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;
    
    // Return true if k is greater than or equal to val
    return (k >= val);
}

// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int u = 0; // number of unique characters
    int n = s.length();
    
    // Associative array to store the count of characters
    int count[MAX_CHARS];
    memset(count, 0, sizeof(count));
    
    // Traverse the string, Fills the associative array
    // count[] and count number of unique characters
    for (int i=0; i<n; i++)
    {
        if (count[s[i]-'a']==0)
            u++;
        count[s[i]-'a']++;
    }
    
    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        cout << "Not enough unique characters";
        return;
    }
    
    // Otherwise take a window with first element in it.
    // start and end variables.
    int curr_start = 0, curr_end = 0;
    
    // Also initialize values for result longest window
    int max_window_size = 1, max_window_start = 0;
    
    // Initialize associative array count[] with zero
    memset(count, 0, sizeof(count));
    
    count[s[0]-'a']++; // put the first character
    
    // Start from the second character and add
    // characters in window according to above
    // explanation
    for (int i=1; i<n; i++)
    {
        // Add the character 's[i]' to current window
        count[s[i]-'a']++;
        curr_end++;
        
        // If there are more than k unique characters in
        // current window, remove from left side
        while (!isValid(count, k))
        {
            cout<<"Moving the start index"<<endl;
            count[s[curr_start]-'a']--;
            curr_start++;
        }
        
        cout<<"Moving on to next character in string - "<<s[i]<<endl;
        // Update the max window size if required
        if (curr_end-curr_start+1 > max_window_size)
        {
            max_window_size = curr_end-curr_start+1;
            max_window_start = curr_start;
        }
    }
    
    cout << "Max sustring is : "
    << s.substr(max_window_start, max_window_size)
    << " with length " << max_window_size << endl;
}


int lengthOfLongestSubstringKDistinct(string s, int k) {
    int count[256] = {0};
    int f = 0, b = 0, distinct = 0;
    int start = 0, max_window = INT_MIN;
    
    for (f = 0; f < s.size(); ++f) {
        if(!count[s[f]]++)
           distinct++;
        
        while(distinct > k) {
            if (!--count[s[b++]])
                distinct--;
        }
        
        if (f - b + 1 > max_window) {
            max_window = f - b + 1;
            start = b;
        }
    }
    
    cout<<s.substr(start, max_window)<<endl;
    
    return 0;
}

// Driver function
int main()
{
    //string s = "aabacbebebe";
    string s = "aebbcc";
    int k = 2;
    kUniques(s, k);
    lengthOfLongestSubstringKDistinct(s, 2);
    return 0;
}
