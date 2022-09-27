#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct CycleQueue {
    int data[maxSize];
    int front, rear;
} CQueue;

bool enQueueTail(CQueue *cq, int val) {
    if ((cq->rear + 1) % maxSize == cq->front) return false;
    cq->rear = (cq->rear + 1) % maxSize;
    cq->data[cq->rear] = val;
    return true;
}

bool enQueueHead(CQueue *cq, int val) {
    if (cq->rear == (cq->front - 1 + maxSize) % maxSize) return false;
    cq->data[cq->front] = val;
    cq->front = (cq->front - 1 + maxSize) % maxSize;
    return true;
}

bool deQueueHead(CQueue *cq, int *val) {
    if (cq->rear == cq->front) return false;
    cq->front = (cq->front + 1) % maxSize;
    *val = cq->data[cq->front];
    return true;
}

bool deQueueTail(CQueue *cq, int *val) {
    if (cq->front == cq->rear) return false;
    *val = cq->data[cq->rear];
    cq->rear = (cq->rear - 1 + maxSize) % maxSize;
    return true;
}

int main() {}