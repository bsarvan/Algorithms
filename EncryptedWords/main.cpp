//
//  main.cpp
//  EncryptedWords
//
//  Created by Bharat Sarvan on 09/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string findEncryptedWord(string s) {
  // Write your code here
    if (s.size() == 1 || s.size() == 0) {
        return s;
    }
    
    int mid_index = 0;
    if (s.size() % 2 ==  1) {
        mid_index = s.size()/2;
    } else {
        mid_index = s.size()/2 - 1;
    }
    
    string R;
    
    R += s[mid_index];
    R.append(findEncryptedWord(s.substr(0, mid_index)));
    R.append(findEncryptedWord(s.substr(mid_index + 1)));
    
    return R;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected);
    cout << " Your output: ";
    printString(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {

  string s_1 = "abc";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
