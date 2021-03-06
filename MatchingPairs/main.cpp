//
//  main.cpp
//  MatchingPairs
//
//  Created by Bharat Sarvan on 19/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Matching Pairs
 Given two strings s and t of length N, find the maximum number of possible matching pairs in strings s and t after swapping exactly two characters within s.
 A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character that is present at the ith and jth index of s, respectively. The matching pairs of the two strings are defined as the number of indices for which s[i] and t[i] are equal.
 Note: This means you must swap two characters at different indices.
 Signature
 int matchingPairs(String s, String t)
 Input
 s and t are strings of length N
 N is between 2 and 1,000,000
 Output
 Return an integer denoting the maximum number of matching pairs
 Example 1
 s = "abcd"
 t = "adcb"
 output = 4
 Explanation:
 Using 0-based indexing, and with i = 1 and j = 3, s[1] and s[3] can be swapped, making it  "adcb".
 Therefore, the number of matching pairs of s and t will be 4.
 Example 2
 s = "mno"
 t = "mno"
 output = 1
 Explanation:
 Two indices have to be swapped, regardless of which two it is, only one letter will remain the same. If i = 0 and j=1, s[0] and s[1] are swapped, making s = "nmo", which shares only "o" with t.
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Add any helper functions you may need here

int FindMatchPairs(string s, string t) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) {
            count++;
        }
    }
    return count;
}


//int matchingPairs(string s, string t) {
//
//    int max_pairs = INT_MIN;
//
//    if (s.size() != t.size()) {
//        return 0;
//    }
//
//    for (int i = 0; i < s.size(); i++) {
//        for (int j = i + 1; j < s.size(); j++ ) {
//            swap(s[i], s[j]);
//            int MatchingPairCount = FindMatchPairs(s, t);
//            max_pairs = max(max_pairs, MatchingPairCount);
//            swap(s[i], s[j]);
//        }
//    }
//    return max_pairs;
//}

int matchingPairs(string s, string t) {
    int diffs = 0;
    int matches = 0;
    int matchPairs = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            diffs++;
        } else {
            matches++;
        }
    }
    
    if (diffs > 2) {
        matchPairs = matches + 1;
    } else if (diffs == 0) {
        matchPairs = matches / 2;
    }else
        matchPairs = s.size();
    
    return matchPairs;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
