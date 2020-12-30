//
//  main.cpp
//  LargestTripleProducts
//
//  Created by Bharat Sarvan on 21/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 Largest Triple Products
 You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive), output[i] is equal to the product of the three largest elements out of arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than three elements).
 Note that the three largest elements used to form any product may have the same values as one another, but they must be at different indices in arr.
 Signature
 int[] findMaxProduct(int[] arr)
 Input
 n is in the range [1, 100,000].
 Each value arr[i] is in the range [1, 1,000].
 Output
 Return a list of n integers output[0..(n-1)], as described above.
 Example 1
 n = 5
 arr = [1, 2, 3, 4, 5]
 output = [-1, -1, 6, 24, 60]
 The 3rd element of output is 3*2*1 = 6, the 4th is 4*3*2 = 24, and the 5th is 5*4*3 = 60.
 Example 2
 n = 5
 arr = [2, 1, 2, 1, 2]
 output = [-1, -1, 4, 4, 8]
 The 3rd element of output is 2*2*1 = 4, the 4th is 2*2*1 = 4, and the 5th is 2*2*2 = 8.
 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Add any helper functions you may need here


vector <int> findMaxProduct(vector <int> arr) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;
    
    if (arr.size() < 3) {
        return {};
    }
        
    pq.push(arr[0]);
    pq.push(arr[1]);
    
    result.emplace_back(-1);
    result.emplace_back(-1);
    
    int cum_prod = arr[0] * arr[1];
    
    for (int i = 2; i < arr.size(); i++) {
        
        cum_prod *=arr[i];
        pq.push(arr[i]);
        
        int tmp = 1;
        if (pq.size() > 3) {
            tmp = pq.top();
            pq.pop();
        }
        
        cum_prod /=tmp;
        
        result.emplace_back(cum_prod);
        
        
//        if (pq.size() > 3) {
//            pq.pop();
//        }
//
//        vector<int> tmp;
//        int prod = 1;
//        int j = 3;
//        while(j--) {
//            tmp.emplace_back(pq.top());
//            cout<<pq.top()<<" ";
//            prod *= pq.top();
//            pq.pop();
//        }
//        cout<<endl;
//
//        j = 0;
//        while(j < 3) {
//            pq.push(tmp[j++]);
//        }
//
//        result.emplace_back(prod);
//
    }
    
    return result;
  
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  vector <int> arr_1{1, 2, 3, 4, 5};
  vector <int> expected_1{-1, -1, 6, 24, 60};
  vector <int> output_1 = findMaxProduct(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{-1, -1, 56, 56, 140, 140};
  vector <int> output_2 = findMaxProduct(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
