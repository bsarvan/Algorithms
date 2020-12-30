//
//  main.cpp
//  QueueImplementation
//
//  Created by Bharat Sarvan on 05/11/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct Queue {
    int size;
    int *arr;
    int count;
    int head;
    int tail;
    
    Queue(int V) {
        arr = (int *)malloc(sizeof(int) * V);
        memset(arr, -1, sizeof(int)*V);
        count = 0;
        size = V;
        head = 0;
        tail = 0;
    }
};

void enqueue(struct Queue &queue, int data) {
    if (queue.count == queue.size) {
        cout<<"Queue is full"<<endl;
        return;
    }
    
    queue.arr[queue.tail] = data;
    queue.tail = (queue.tail + 1)%queue.size;
    queue.count++;
}


int dequeue(struct Queue &queue) {
    if (queue.count == 0) {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int tmp = queue.arr[queue.head];
    queue.arr[queue.head] = -1;
    queue.head = (queue.head + 1) % queue.size;
    queue.count--;
    
    return tmp;
}

void printQueue(struct Queue queue) {
    for (int i=0;i<queue.size;i++) {
        cout<<queue.arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    cout<<"Algorithm to implement a queue using arrays"<<endl;
    
    struct Queue Q(5);
    
    cout<<"Enqueuing"<<endl;
    for (int i = 0; i < 3; i++) {
        enqueue(Q, i);
    }
    
    printQueue(Q);
    
    cout<<Q.count<<endl;
    
    cout<<"Dequeuing"<<endl;
    
    for (int i = 0; i<3; i++) {
        cout<<dequeue(Q)<<" ";
    }
    
    cout<<endl;
    return 0;
}
