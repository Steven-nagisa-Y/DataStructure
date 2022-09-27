#include <stdlib.h>

typedef struct DLinkedList {
    int val;
    struct DLinkedList *prev;
    struct DLinkedList *next;
} DListNode;

/**
 * @brief Create DoubleLinkedList from tail
 *
 * @param a integer array;
 * @param n length of integer array
 */
DListNode *createDListTail(int a[], int n) {
    DListNode *s, *r;
    int i;
    DListNode *L = (DListNode *)malloc(sizeof(DListNode));
    L->prev = NULL;
    L->next = NULL;
    r = L;
    for (i = 0; i < n; ++i) {
        s = (DListNode *)malloc(sizeof(DListNode));
        s->val = a[i];
        r->next = s;
        s->prev = r;
        r = s;
    }
    r->next = NULL;
    return L;
}

DListNode *findNode(DListNode *C, int x) {
    DListNode *p = C->next;
    while (p != NULL) {
        if (p->val == x) break;
        p = p->next;
    }
    return p;
}

/**
 * @brief insert a num to Double Linked List
 *
 * @param List a list to be inserted
 * @param x a num before the position to be inserted
 * @param val a num to insert
 */
void insertNode(DListNode *List, int x, int val) {
    DListNode *s;
    s = findNode(List, x);
    if (s == NULL) return;
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    newNode->val = val;
    newNode->next = s->next;
    newNode->prev = s;
    s->next = newNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

/**
 * @brief delete a particular num from a list
 *
 * @param List a list to be deleted from
 * @param x a num to be deleted
 */
void deleteNode(DListNode *List, int x) {
    DListNode *s = findNode(List, x);
    if (s == NULL) return;
    if (s->prev == NULL) {
        if (s->next != NULL) {
            s->next->prev = NULL;
            s->next = NULL;
            free(s);
        } else {
            s = NULL;
        }
    } else {
        if (s->next != NULL) {
            DListNode *p = s->prev;
            p->next = s->next;
            s->next->prev = p;
            free(s);
        } else {
            s->prev->next = NULL;
            free(s);
        }
    }
}

#include <stdio.h>
/**
 * @brief Print a DoubleLinkedList
 *
 * @param A ListNode Variable
 */
void printListNode(DListNode A) {
    DListNode *p = A.next;
    int i = 0;
    while (p != NULL) {
        i++;
        printf("%d ", p->val);
        p = p->next;
    }
    printf("[len: %d]\n", i);
}