#include <stdlib.h>

#include "LinkedList.h"

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *A = createListTail(a, 10);
    printListNode(A);
    // 找倒数第五个节点的值
    const int N = 5;
    ListNode *Target = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = A;
    int i = N;
    while (i) {
        Target = p->next;
        p = p->next;
        i--;
    }
    while (Target != NULL) {
        Target = Target->next;
        A = A->next;
    }
    printf("Find #%d from last: %d\n", N, A->val);
    return 0;
}