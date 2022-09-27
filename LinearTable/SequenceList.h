#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 999999

typedef struct SeqList {
    int data[MAX];
    int len;
} SeqList;

typedef struct SeqListChar {
    char data[MAX];
    int len;
} SeqListChar;

bool insertElem(SeqList *list, int val, int index) {
    int i;
    if (index < 0 || index > list->len || list->len == MAX) return false;
    for (i = list->len; i >= index; --i) list->data[i + 1] = list->data[i];
    list->data[index] = val;
    list->len++;
    return true;
}

int findElem(SeqList list, int target) {
    int i;
    for (i = 0; i < list.len; ++i) {
        if (target == list.data[i]) return i;
    }
    return -1;
}

bool deleteElem(SeqList *list, int index, int *ret) {
    int i;
    if (index < 0 || index > list->len) return false;
    *ret = list->data[index];
    for (i = index; i < list->len; ++i) {
        list->data[i] = list->data[i + 1];
    }
    list->len--;
    return false;
}

void printList(SeqList list) {
    int i;
    for (i = 0; i < list.len; i++) {
        printf("%d", list.data[i]);
        if (i != list.len - 1)
            printf(" ");
        else
            printf("\n");
    }
}

void printListChar(SeqListChar list) {
    int i;
    for (i = 0; i < list.len; i++) {
        printf("%c", list.data[i]);
        if (i != list.len - 1)
            printf(" ");
        else
            printf("\n");
    }
}

void reverseChar(SeqListChar *list, int left, int right, int k) {
    char tmp;
    for (int i = left, j = right; i < left + k && i < j; ++i, --j) {
        tmp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = tmp;
    }
}

void reverse(SeqList *list, int left, int right, int k) {
    int tmp;
    for (int i = left, j = right; i < left + k && i < j; ++i, --j) {
        tmp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = tmp;
    }
}

void moveCharToEnd(SeqListChar *list, int k) {
    reverseChar(list, 0, k - 1, k);
    reverseChar(list, 0, list->len - 1, k);
}