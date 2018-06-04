//
//  main.c
//  InitTable
//
//  Created by bsarvan on 22/04/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <stdio.h>

struct abc {
    int data;
};
struct abc table[5];


void InitTable(struct abc *table) {
    int i;
    for(i = 2; i<5; i++){
        table[i].data = 55;
    }
    return;
}
int main(int argc, const char * argv[]) {
    int i;
    printf("Hello, World!\n");
    InitTable(table);
    for(i = 0;i<5;i++){
        printf("Contents of table - %d \n", table[i].data);
    }
    printf("\n");
    return 0;
}
