//
//  main.c
//  StackCheckTest
//
//  Created by bsarvan on 26/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include<stdio.h>

void print_byte(void *number, int order)
{
    unsigned i = 0;
    
    i = (*(int *)number >> (8*order)) & 0x000000FF;
    
    printf("Number:0x%08x, Address - %p, Byte:%02x, Order:%d\n",*(int *)number,(char *)number+order, i, order);
    //printf("Address - %p, Value - %02x\n", (char *)number + order, *(number + order));
    
    return;
}

void func(void *a, size_t *b) {
    *(int *)a = 2;
    *b = (sizeof(int));
    return;
}

int main() {
    int i = 0;

    int x,y;
    printf("Size of int - %d\n", sizeof(int));
    printf("x - %p, y - %p\n",&x, &y);
    func((void *)&x, (void *)&y);
    
    printf("x - %p - %d\n", &x, x);
    printf("y - %p - %d\n", &y, y);

#if 0
    int xx = 4;
    int yy = 8;
    
    printf("Address of xx - %p\n", &xx);
    printf("Address of yy - %p\n", &yy);
    
    
#endif
    
    printf("Printing Bytes of Memory location for variable yy\n");
    for (i = 0; i < 8; i++) {
        print_byte((char *)&y,i);
    }
    
    printf("Printing Bytes of Memory location for variable xx\n");
    for (i = 0; i < 8; i++) {
        print_byte((char *)&x,i);
    }
    
    
    return 0;
}





