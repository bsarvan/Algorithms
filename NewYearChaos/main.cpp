//
//  main.cpp
//  NewYearChaos
//
//  Created by Bharat Sarvan on 19/12/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//


// Problem from HackerRank

/*
 It is New Year's Day and people are in line for the Wonderland rollercoaster ride. Each person wears a sticker indicating their initial position in the queue. Initial positions increment by  from  at the front of the line to  at the back.

 Any person in the queue can bribe the person directly in front of them to swap positions. If two people swap positions, they still wear the same sticker denoting their original places in line. One person can bribe at most two others. For example, if  and  bribes , the queue will look like this: .

 Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to get the queue into its current state. If anyone has bribed more than two people, the line is too chaotic to compute the answer.

 Function Description

 Complete the function minimumBribes in the editor below.

 minimumBribes has the following parameter(s):

 int q[n]: the positions of the people after all bribes
 Returns

 No value is returned. Print the minimum number of bribes necessary or Too chaotic if someone has bribed more than  people.
 Input Format

 The first line contains an integer , the number of test cases.

 Each of the next  pairs of lines are as follows:
 - The first line contains an integer , the number of people in the queue
 - The second line has  space-separated integers describing the final state of the queue.

 Constraints

 Subtasks

 For  score
 For  score

 Sample Input

 2
 5
 2 1 5 3 4
 5
 2 5 1 3 4
 Sample Output

 3
 Too chaotic
 
 */


#include <iostream>
#include <vector>
using namespace std;

class TreeNode;

class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    int count = 1;
    TreeNode(int val) {
        this->val = val;
    }
};
    
int insertNode(TreeNode *root, int val) {
    TreeNode *curr = root;
    int thisCount = 0;
    
    while(true) {
        if(val <= curr->val) {
            curr->count++;
            if(curr->left == NULL) {
                curr->left = new TreeNode(val);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            thisCount += curr->count;
            if(curr->right == NULL) {
                curr->right = new TreeNode(val);
                break;
            } else {
                curr = curr->right;
            }
        }
    }
    return thisCount;
}


void FindMinimumBribes(vector<int> nums) {
    vector<int> res;
    int total_bribes = 0;
    
    TreeNode *root = new TreeNode(nums[nums.size() - 1]);
    
    res.emplace_back(0);
    
    for(int i = nums.size() - 2; i >= 0; i--) {
        
        int count = insertNode(root, nums[i]);
        res.insert(res.begin(),count);
    }
    
    bool isChaotic = false;
    for (auto c:res) {
        if (c > 2) {
            isChaotic = true;
            break;
        }
        total_bribes +=c;
    }

    if (isChaotic == true) {
        cout<<"Too chaotic"<<endl;
    } else {
        cout<<total_bribes<<endl;
    }
    return;
}


//void FindMinimumBribes(vector<int> q) {
//    vector<int> count(q.size(), 0);
//    int total_bribes = 0;
//
//    for (int i = 0; i < q.size(); i++) {
//        int val = q[i];
//        for (int j = i + 1; j < q.size(); j++) {
//            if (q[j] < val) {
//                count[i]++;
//                total_bribes++;
//            }
//        }
//    }
//
//    bool isChaotic = false;
//    for (auto c:count) {
//        if (c > 2) {
//            isChaotic = true;
//            break;
//        }
//    }
//
//    if (isChaotic == true) {
//        cout<<"Too chaotic"<<endl;
//    } else {
//        cout<<total_bribes<<endl;
//    }
//    return;
//}

int main(int argc, const char * argv[]) {
    vector<int> queue = {2, 1, 5, 3, 4};
//    vector<int> queue = {1, 2, 5, 3, 7, 8, 6, 4};
    
    cout<<"Algorithm to find the minimum number of bribes required to have the Q in the current state"<<endl;
    FindMinimumBribes(queue);
    
    return 0;
}
