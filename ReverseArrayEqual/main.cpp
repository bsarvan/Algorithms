//
//  main.cpp
//  ReverseArrayEqual
//
//  Created by Bharat Sarvan on 16/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Given two arrays A and B of length N, determine if there is a way to make A equal to B by reversing any subarrays from array B any number of times.
 Signature
 bool areTheyEqual(int[] arr_a, int[] arr_b)
 Input
 All integers in array are in the range [0, 1,000,000,000].
 Output
 Return true if B can be made equal to A, return false otherwise.
 Example
 A = [1, 2, 3, 4]
 B = [1, 4, 3, 2]
 output = true
 After reversing the subarray of B from indices 1 to 3, array B will equal array A.
 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  // Write your code here
    if (array_a.size() != array_b.size()) {
        return false;
    }
    
    unordered_set<int> S;
    
    for (auto a:array_a) {
        S.emplace(a);
    }
    
    for (auto b:array_b) {
        if (S.find(b) == S.end()) {
            return false;
        }
    }

    int i = 0;
    int count = 0;
    for (i = 0; i < array_b.size() - 1; i++) {
        if (array_b[i] < array_b[i + 1]) {
            count++;
        } else {
            break;
        }
    }
    
    for (int j = i; j < array_b.size() -1 ; j++) {
        if (array_b[j] > array_b[j+1]) {
            count++;
        } else {
            break;
        }
    }
    
    if (count != array_b.size() - 1) {
        return false;
    }
    return true;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl;
  }
  test_case_number++;
}

int main(){
  vector <int> array_a_1{1, 2, 3, 4};
  vector <int> array_b_1{1, 4, 3, 2};
  bool expected_1 = true;
  bool output_1 = areTheyEqual(array_a_1, array_b_1);
  check(expected_1, output_1);

  vector <int> array_a_2{1, 2, 3, 4};
  vector <int> array_b_2{1, 4, 3, 3};
  bool expected_2 = false;
  bool output_2 = areTheyEqual(array_a_2, array_b_2);
  check(expected_2, output_2);


  // Add your own test cases here
  
  return 0;
}
