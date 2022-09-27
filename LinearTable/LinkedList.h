#include <stdlib.h>

typedef struct LinkedList {
    int val;
    struct LinkedList *next;
} ListNode;

/**
 * @brief Merge two LinkedList with head Node
 *
 * @param A LinkedList
 * @param B LinkedList
 * @return ListNode* New Sorted LinkedList
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *s;
    ListNode *R = (ListNode *)malloc(sizeof(ListNode));
    R->next = NULL;
    s = R;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            s->next = l1;
            l1 = l1->next;
            s = s->next;
        } else {
            s->next = l2;
            l2 = l2->next;
            s = s->next;
        }
    }
    if (l1 != NULL) s->next = l1;
    if (l2 != NULL) s->next = l2;
    return R->next;
}

void mergeRef(ListNode *A, ListNode *B, ListNode *C) {
    ListNode *p = A->next;
    ListNode *q = B->next;
    ListNode *s;
    C = A;
    C->next = NULL;
    while (p != NULL && q != NULL) {
        if (p->val <= q->val) {
            s = p;
            p = p->next;
            s->next = C->next;
            C->next = s;
        } else {
            s = q;
            q = q->next;
            s->next = C->next;
            C->next = s;
        }
    }
    if (p != NULL) {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }

    if (q != NULL) {
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
}

ListNode *createListTail(int a[], int n) {
    ListNode *s, *r;
    int i;
    ListNode *R = (ListNode *)malloc(sizeof(ListNode));
    R->next = NULL;
    r = R;
    for (i = 0; i < n; ++i) {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->val = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
    return R;
}

ListNode *createListHead(int a[], int n) {
    ListNode *s;
    int i;
    ListNode *R = (ListNode *)malloc(sizeof(ListNode));
    R->next = NULL;
    for (i = 0; i < n; ++i) {
        s = (ListNode *)malloc(sizeof(ListNode));
        s->val = a[i];
        s->next = R->next;
        R->next = s;
    }
    return R;
}

int deleteNode(ListNode *C, int x) {
    ListNode *p, *q;
    p = C;
    while (p->next != NULL) {
        if (p->next->val == x) break;
        p = p->next;
    }
    if (p->next == NULL)
        return 0;
    else {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
}

#include <stdio.h>
/**
 * @brief Print a LinkedList
 *
 * @param A ListNode Variable
 */
void printListNode(ListNode *A) {
    ListNode *p = A->next;
    int i = 0;
    while (p != NULL) {
        ++i;
        printf("%d ", p->val);
        p = p->next;
    }
    printf("[length: %d]\n", i);
}