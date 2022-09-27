#include <stdio.h>

#include "DoubleLinkedList.h"

int main() {
    int a[] = {1, 3, 5, 7, 9};
    DListNode *L = createDListTail(a, 5);
    printListNode(*L);
    insertNode(L, 1, 2);
    insertNode(L, 3, 4);
    printListNode(*L);
    return 0;
}