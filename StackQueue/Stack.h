#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

const unsigned int MAX_SIZE = SIZE;

typedef struct Stack {
    int data[SIZE];
    int top;
} Stack;

typedef struct StackNode {
    int data;
    struct StackNode *next;
} SNode;

/**
 * @brief Initialize a stack, set top flag to -1
 *
 * @param stack
 */
void initStack(Stack *s) { s->top = -1; }

bool isEmpty(Stack s) {
    if (s.top == -1)
        return true;
    else
        return false;
}

bool push(Stack *s, int val) {
    if (s->top == SIZE - 1) return false;

    ++(s->top);
    s->data[s->top] = val;
    return true;
}

bool pop(Stack *s, int *val) {
    if (s->top == -1) return false;

    *val = s->data[s->top];
    --(s->top);
    return true;
}

void initLStack(SNode *head) {
    head = (SNode *)malloc(sizeof(SNode));
    head->next = NULL;
}

bool isEmptyL(SNode *head) {
    if (head->next == NULL)
        return true;
    else
        return false;
}

void pushL(SNode *head, int val) {
    SNode *p = (SNode *)malloc(sizeof(SNode));
    p->next = NULL;
    // 头插法
    p->data = val;
    p->next = head->next;
    head->next = p;
}

bool popL(SNode *head, int *val) {
    SNode *p;
    if (head->next == NULL) return false;
    p = head->next;
    *val = p->data;
    head->next = p->next;
    free(p);
    return true;
}