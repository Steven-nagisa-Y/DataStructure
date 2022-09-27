#include <stdlib.h>

#include "LinkedList.h"

void diffLinkedList(ListNode *A, ListNode *B) {
    ListNode *p = A->next, *q = B->next;
    while (q != NULL) {
        if (p->val == q->val) {
            deleteNode(A, q->val);
            p = p->next;
            q = q->next;
            continue;
        }
        if (p->val < q->val) {
            p = p->next;
            continue;
        }
        if (p->val > q->val) {
            q = q->next;
        }
    }
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 11};
    int b[] = {1, 2, 3, 4, 10};
    ListNode *A = createListTail(a, 6);
    ListNode *B = createListTail(b, 5);
    printListNode(A);
    printListNode(B);
    diffLinkedList(A, B);
    printListNode(A);
    return 0;
}