//
//  main.cpp
//  BillionUsers
//
//  Created by Bharat Sarvan on 08/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int getBillionUsersDay(vector <float> growthRates) {
    // Write your code here
    
    long userCount = 0;
    int day = 1;
    while(userCount < 1000000000) {
        userCount = 0;
        for (int i = 0; i < growthRates.size(); i++) {
            userCount += pow(growthRates[i], day);
        }
        day++;
    }

    return day - 1 ;
}

#define TARGET_USER_COUNT 1000000000

long getBillionUsersDay_v2 (vector<float> growthRates) {
    long low = 1;
    long high = 2000;
    
    while(low < high) {
        long mid = low + (high - low)/2;
        
        unsigned long long userCount = 0;
        for (auto rate : growthRates) {
            userCount += pow(rate, mid);
        }
        
        if (userCount == TARGET_USER_COUNT) {
            return mid;
        } else if (userCount < TARGET_USER_COUNT) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return low;
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
    
    vector <float> test_1{1.1, 1.2, 1.3};
    int expected_1 = 79;
    int output_1 = getBillionUsersDay_v2(test_1);
    check(expected_1, output_1);
    
    vector <float> test_2{1.01, 1.02};
    int expected_2 = 1047;
    int output_2 = getBillionUsersDay_v2(test_2);
    check(expected_2, output_2);
    
    // Add your own test cases here
    
}
