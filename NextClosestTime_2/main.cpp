//
//  main.cpp
//  NextClosestTime
//
//  Created by bsarvan on 13/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

/*
 
 
 Store the available <4 digit in set(sorted from minimum to maximum natrually);
 Start from end of the time string, replace it with the next larger number in the set. If available and a legal time(min < 60 && hh <24), return the result;
 Else replace it the smalleset number int the set , go to the next digit in the time string.
 Space is O(1), because <4 characters set; time is O(1), which goes through 4 characters in the string
 
 
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
 
 You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
 
 Example 1:
 
 Input: "19:34"
 Output: "19:39"
 Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
 Example 2:
 
 Input: "23:59"
 Output: "22:22"
 Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 
 */
#include <iostream>
#include <set>
using namespace std;

string nextClosestTime(string time) {
    set<char> sorted;
    for(auto c:time){
        if(c==':') continue;
        sorted.insert(c);
    }
    
    string res = time;
    for(int i = time.size() -1; i>=0; i--){
        if(time[i] == ':' ) continue;
        auto it = sorted.find(time[i]);
        cout<<"it "<<*it<<" , time[i] "<<time[i]<<endl;
        if(*it != *sorted.rbegin()){// not the largest number
            it++; // go to the next element
            cout<<"Next largest "<<*it<<endl;
            res[i] = *it;
            cout<<res<<endl;
            if((i>=3 && stoi(res.substr(3,2))<60) ||((i<2) && stoi(res.substr(0,2))<24))
                return res;
        }
        cout<<"Here "<<endl;
        res[i]=*sorted.begin(); // take the smallest number
        cout<<res<<endl;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    //string time = "19:54";
    string time = "12:59";
    
    string res = nextClosestTime(time);
    cout<<"Next Closest Time to "<<time<<" is "<<res<<endl;
    return 0;
}
