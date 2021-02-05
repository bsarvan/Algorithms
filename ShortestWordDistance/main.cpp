//
//  main.cpp
//  ShortestWordDistance
//
//  Created by bsarvan on 04/03/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

 Example:
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

 Input: word1 = “coding”, word2 = “practice”
 Output: 3
 Input: word1 = "makes", word2 = "coding"
 Output: 1
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int shortestDistance(vector<string>& words, string word1, string word2) {
    int i1 = -1;
    int i2 = -1;
    int min_distance = INT_MAX;

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) i1 = i;
        else if (words[i] == word2) i2 = i;

        if (i1 != -1 and i2 != -1) {
            min_distance = min(min_distance, abs(i1 - i2));
        }
    }

    return min_distance;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    
    cout<<"Algorithm to find the shortest distance between given two words"<<endl;
    string word1 = "practice";
    string word2 = "coding";
    int result = shortestDistance(words, word1, word2);
    
    cout<<"Input - [ ";
    for (auto &word : words) {
        cout<<word<<" ";
    }
    cout<<"]"<<endl;
    cout<<"Shortest Distance between words "<<word1<<" and "<<word2<<" is "<<result<<endl;
    return 0;
}
