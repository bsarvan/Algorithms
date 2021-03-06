//
//  main.cpp
//  ChoooseRandomFromStream
//
//  Created by bsarvan on 29/01/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>

// An efficient C program to randomly select a number from stream of numbers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to randomly select a item from stream[0], stream[1], .. stream[i-1]
int selectRandom(int x)
{
    static int res; // The resultant random number
    static int count = 0; //Count of numbers visited so far in stream
    
    count++; // increment count of numbers seen so far
    
    // If this is the first element from stream, return it
    if (count == 1) {
        printf("First element in the stream\n");
        res = x;
    } else
    {
        // Generate a random number from 0 to count - 1
        int i = rand() % count;
        
        // Replace the prev random number with new number with 1/count probability
        if (i == count - 1) {
            printf("Updating the last result\n");
            res = x;
        }
    }
    return res;
}

// Driver program to test above function.
int main()
{
    int stream[] = {1, 2, 3, 4};
    int n = sizeof(stream)/sizeof(stream[0]);
    
    // Use a different seed value for every run.
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        printf("Random number from first %d numbers is %d \n",
               i+1, selectRandom(stream[i]));
    return 0;
}
