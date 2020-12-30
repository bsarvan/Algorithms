//
//  main.cpp
//  OptimalMoveToWin
//
//  Created by Bharat Sarvan on 15/11/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

/*
 The game of Nim is played as follows. Starting with three heaps, each containing a variable number of items, two players take turns removing one or more items from a single pile. The player who eventually is forced to take the last stone loses. For example, if the initial heap sizes are 3, 4, and 5, a game could be played as shown below:

   A  |  B  |  C
 -----------------
   3  |  4  |  5
   3  |  1  |  3
   3  |  1  |  3
   0  |  1  |  3
   0  |  1  |  0
   0  |  0  |  0
 In other words, to start, the first player takes three items from pile B. The second player responds by removing two stones from pile C. The game continues in this way until player one takes last stone and loses.

 Given a list of non-zero starting values [a, b, c], and assuming optimal play, determine whether the first player has a forced win.
 
 */
#include <iostream>
#include <vector>
using namespace std;



vector<vector<int>> get_all__moves(vector<int> heap) {
    
    vector<vector<int>> result;
    
    result.emplace_back(heap);
    
    for (int pile = 0; pile < heap.size(); pile++) {
        
        for (int heap_size = 1; heap_size <= heap[pile]; heap_size++) {
            int tmp = heap[pile];
            heap[pile] -= heap_size;
            result.emplace_back(heap);
            heap[pile] = tmp;
        }
        
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to find the forced winner"<<endl;
    vector<int> heap_input = {3,4,5};
    
    vector<vector<int>> R = get_all__moves(heap_input);
    
    for (auto r : R ) {
        for (auto v : r) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
