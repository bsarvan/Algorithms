//
//  main.cpp
//  DecodeString
//
//  Created by bsarvan on 15/12/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

// C++ program to decode a string recursively
// encoded as count followed substring

/*
 Given an encoded string, return its decoded string.

 The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is
 being repeated exactly k times. Note that k is guaranteed to be a positive integer.

 You may assume that the input string is always valid; No extra white spaces, square brackets
 are well-formed, etc.

 Furthermore, you may assume that the original data does not contain any digits and that digits
 are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 Examples:

 s = "3[a]2[bc]", return "aaabcbc".
 s = "3[a2[c]]", return "accaccacc".
 s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 
 */

#include <iostream>
#include <stack>
using namespace std;

// Returns decoded string for 'str'
string decode(string str)
{
    stack<int> integerstack;
    stack<char> stringstack;
    string temp = "", result = "";

    // Traversing the string
    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;

        // If number, convert it into number
        // and push it into integerstack.
        if (str[i] >= '0' && str[i] <='9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            integerstack.push(count);
        }

        // If closing bracket ']', pop elemment until
        // '[' opening bracket is not found in the
        // character stack.
        else if (str[i] == ']')
        {
            temp = "";
            count = 0;

            if (! integerstack.empty())
            {
                count = integerstack.top();
                integerstack.pop();
            }

            while (! stringstack.empty() && stringstack.top()!='[' )
            {
                temp = stringstack.top() + temp;
                stringstack.pop();
            }

            if (! stringstack.empty() && stringstack.top() == '[')
                stringstack.pop();

            // Repeating the popped string 'temo' count
            // number of times.
            for (int j = 0; j < count; j++)
                result = result + temp;

            // Push it in the character stack.
            for (int j = 0; j < result.length(); j++)
                stringstack.push(result[j]);

            result = "";
        }

        // If '[' opening bracket, push it into character stack.
        else if (str[i] == '[')
        {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                stringstack.push(str[i]);
            else
            {
                stringstack.push(str[i]);
                integerstack.push(1);
            }
        }

        else
            stringstack.push(str[i]);
    }

    // Pop all the elmenet, make a string and return.
    while (! stringstack.empty())
    {
        result = stringstack.top() + result;
        stringstack.pop();
    }

    return result;
}

// Driven Program
int main()
{
    //string str = "3[b2[ca]]";
    string str = "3[b]10[a]";
    cout << decode(str) << endl;
    return 0;
}
