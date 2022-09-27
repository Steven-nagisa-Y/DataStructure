#include <stdio.h>

#include "LinkedList.h"

/**
 * @brief 利用递归压入栈的性质实现从后往前打印链表
 *
 * @param list a linked list to be printed
 */
void printFromLast(ListNode *list) {
    if (list == NULL) return;
    printFromLast(list->next);
    printf("%d ", list->val);
}

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *list = createListTail(a, 10);
    printFromLast(list->next);
    return 0;
}
