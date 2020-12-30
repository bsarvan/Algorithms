//
//  main.cpp
//  PairsSums
//
//  Created by Bharat Sarvan on 15/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numberOfWays(vector<int>& arr, int k) {
  // Write your code here
  if (arr.size() == 0 ) {
    return 0;
  }
  
  sort(arr.begin(), arr.end());
  
  int low = 0;
  size_t high = arr.size() - 1;
  int count_sums = 0;
  
  while(low < high) {
    int sum = arr[low] + arr[high];
   if (sum > k) {
      high--;
    } else if (sum < k) {
      low++;
    } else {
     
        count_sums++;
     
        if (arr[low] == arr[high]) {
            cout<<"Indexes when equal - "<<low<<" "<<high<<endl;
            size_t tmp_high = high - 1;
            cout<<"Iterating high index to low - "<<low<<" "<<tmp_high<<endl;
            while(low < tmp_high) {
                count_sums++;
                tmp_high--;
            }

            size_t tmp_low = low + 1;
            cout<<"Interating low index to high - "<<tmp_low<<" "<<high<<endl;
            while(tmp_low < high) {
                tmp_low++;
                count_sums++;
            }
       
            break;
        }
        low++;
     
    }
  }
    
  return count_sums;
  
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

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}