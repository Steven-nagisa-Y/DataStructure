#include <stdlib.h>

#include "LinkedList.h"

void reverse(ListNode *head) {
    ListNode *p = head->next, *q;
    head->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *list = createListTail(a, 10);
    printListNode(list);
    reverse(list);
    printListNode(list);
    return 0;
}
