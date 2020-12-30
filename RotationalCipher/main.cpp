//
//  main.cpp
//  RotationalCipher
//
//  Created by Bharat Sarvan on 15/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


/*
 Rotational Cipher
 One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
 For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.
 Given a string and a rotation factor, return an encrypted string.
 Signature
 string rotationalCipher(string input, int rotationFactor)
 Input
 1 <= |input| <= 1,000,000
 0 <= rotationFactor <= 1,000,000
 Output
 Return the result of rotating input a number of times equal to rotationFactor.
 Example 1
 input = Zebra-493?
 rotationFactor = 3
 output = Cheud-726?
 Example 2
 input = abcdefghijklmNOPQRSTUVWXYZ0123456789
 rotationFactor = 39
 output = nopqrstuvwxyzABCDEFGHIJKLM9012345678
 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Add any helper functions you may need here


string rotationalCipher(string input, int rotationFactor) {
  
    if (input.empty()) {
        return "";
    }
    
    if (rotationFactor == 0) {
        return input;
    }

    string result;
    for (auto a:input) {
        if (isalpha(a)) {
            char base_val = isupper(a)?'A':'a';
            int V = a - base_val + rotationFactor;
            int offset = V % 26;
            int tmp_val =  base_val + offset;
            result.push_back(tmp_val);
        } else if (isdigit(a)) {
            int digit = a - '0';
            int val = (digit + rotationFactor) % 10;
            result += '0' + val;
        } else {
            result.push_back(a);
        }
    }
    
    return result;
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

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);
  // Add your own test cases here
  
}
