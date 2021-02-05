//
//  main.cpp
//  CombinationSum_III
//
//  Created by Bharat Sarvan on 04/01/21.
//  Copyright © 2021 bsarvan. All rights reserved.
//

/*
 
 Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

 Only numbers 1 through 9 are used.
 Each number is used at most once.
 Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

  

 Example 1:

 Input: k = 3, n = 7
 Output: [[1,2,4]]
 Explanation:
 1 + 2 + 4 = 7
 There are no other valid combinations.
 Example 2:

 Input: k = 3, n = 9
 Output: [[1,2,6],[1,3,5],[2,3,4]]
 Explanation:
 1 + 2 + 6 = 9
 1 + 3 + 5 = 9
 2 + 3 + 4 = 9
 There are no other valid combinations.
 Example 3:

 Input: k = 4, n = 1
 Output: []
 Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.
 Example 4:

 Input: k = 3, n = 2
 Output: []
 Explanation: There are no valid combinations.
 Example 5:

 Input: k = 9, n = 45
 Output: [[1,2,3,4,5,6,7,8,9]]
 Explanation:
 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 ​​​​​​​There are no other valid combinations.
  

 Constraints:

 2 <= k <= 9
 1 <= n <= 60
 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void combinationsSum3Helper(vector<int> candidates, int n, int k, int index, vector<int> &combination, vector<vector<int>> &result) {
        
        if (combination.size() == k and n == 0) {
            result.emplace_back(combination);
            return;
        } else if (combination.size() == k or n < 0) {
            return;
        }

   
        
//        const int num_remaining = k - combination.size();
//        for (int i = index; i < candidates.size()  and num_remaining <= candidates.size() - i + 1; ++i) {
        for (int i = index; i < candidates.size(); ++i) {
            
            combination.emplace_back(candidates[i]);
            combinationsSum3Helper(candidates, n - candidates[i], k, i + 1, combination, result);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        
        for(int i = 1; i <= 9; i++) {
            candidates.emplace_back(i);
        }
        
        vector<vector<int>> combinations;
        vector<int> combination;
        
        combinationsSum3Helper(candidates, n, k, 0, combination, combinations);

        return combinations;
    }
};

int main(int argc, const char * argv[]) {
   
    int n = 9;
    int k = 3;
    
    cout<<"Algorithm to build valid combinations of k numbers"<<endl;
    
    Solution sol;
    auto results = sol.combinationSum3(k, n);
    
    for(auto result : results ) {
        for (auto r : result) {
            cout<<r<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
