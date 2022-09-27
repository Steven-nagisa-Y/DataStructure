#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

const unsigned int MAX_SIZE = SIZE;

typedef struct Queue {
    int data[SIZE];
    int front;
    int rear;
} Queue;

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QNode;

typedef struct LinkedQueue {
    QNode *front;
    QNode *rear;
} LQueue;

/**
 * @brief Initialize a Sequential Queue by setting front=rear=0
 *
 * @param q
 */
void initQueue(Queue *q) { q->front = q->rear = 0; }

bool isQueueEmpty(Queue *q) {
    if (q->front == q->rear)
        return true;
    else
        return false;
}

bool enQueue(Queue *q, int val) {
    if ((q->rear + 1) % MAX_SIZE == q->front) return false;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = val;
    return true;
}

bool deQueue(Queue *q, int *val) {
    if (q->front == q->rear) return false;
    q->front = (q->front + 1) % MAX_SIZE;
    *val = q->data[q->front];
    return true;
}

void initLQueue(LQueue *lq) { lq->front = lq->rear = NULL; }

bool isLQueueEmpty(LQueue *lq) {
    if (lq->rear == NULL || lq->front == NULL)
        return true;
    else
        return false;
}

void enLQueue(LQueue *lq, int val) {
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->data = val;
    node->next = NULL;
    if (lq->rear == NULL) {
        lq->front = lq->rear = node;
    } else {
        lq->rear->next = node;
        lq->rear = node;
    }
}

bool deLQueue(LQueue *lq, int *val) {
    QNode *node;
    if (lq->rear = NULL)
        return false;
    else
        node = lq->front;
    // 判断是否只有一个节点
    if (lq->front == lq->rear)
        lq->front = lq->rear = NULL;
    else
        lq->front = lq->front->next;
    *val = node->data;
    free(node);
    return true;
}