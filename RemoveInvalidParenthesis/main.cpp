//
//  main.cpp
//  RemoveInvalidParenthesis
//
//  Created by Bharat Sarvan on 06/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

 Note: The input string may contain letters other than the parentheses ( and ).

 Example 1:

 Input: "()())()"
 Output: ["()()()", "(())()"]
 Example 2:

 Input: "(a)())()"
 Output: ["(a)()()", "(a())()"]
 Example 3:

 Input: ")("
 Output: [""]
 */


#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

// method checks if character is parenthesis(open
// or closed)
bool isParenthesis(char c)
{
    return ((c == '(') || (c == ')'));
}

// method returns true if string contains valid
// parenthesis
bool isValidString(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return (cnt == 0);
}

// method to remove invalid parenthesis
vector<string> removeInvalidParenthesis(string str)
{
    vector<string> result;
    
    if (str.empty())
        return {} ;

    // visit set to ignore already visited string
    set<string> visit;

    // queue to maintain BFS
    queue<string> q;
    string temp;
    bool level = false;

    // pushing given string as starting node into queue
    q.push(str);
    visit.insert(str);
    while (!q.empty())
    {
        str = q.front(); q.pop();
//        cout<<"Processing string - "<<str<<endl;
        if (isValidString(str))
        {
//            cout << "Found -- " << str << endl;
            result.emplace_back(str);

            // If answer is found, make level true
            // so that valid string of only that level
            // are processed.
            level = true;
        }
        if (level)
            continue;
        for (int i = 0; i < str.length(); i++)
        {
            if (!isParenthesis(str[i]))
                continue;

            // Removing parenthesis from str and
            // pushing into queue,if not visited already
            temp = str.substr(0, i) + str.substr(i + 1);
//            cout<<temp<<endl;
            if (visit.find(temp) == visit.end())
            {
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
    
    return result;
}

// Driver code to check above methods
int main()
{
    string expression = "()())()";
    vector<string> res = removeInvalidParenthesis(expression);
    
    for (auto r : res) {
        cout<<r<<endl;
    }

    expression = "()v)";
    removeInvalidParenthesis(expression);

    return 0;
}
