#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 999

/**
 * 定义：串是由零个或多个字符组成的有限序列，字符的个数成为串的长度。数组的长度比串多1，因为数组末尾含有\0
 */

/**
 * @brief 定长串，已经分配好MAX+1的内存
 *
 */
typedef struct {
    char s[MAX + 1];
    unsigned int len;
} StrL;

/**
 * @brief 【常用】变长串，需要用malloc()分配内存
 *
 */
typedef struct String {
    char *chs;
    unsigned int len;
} Str;

Str *initStr() {
    Str *res = (Str *)malloc(sizeof(Str));
    res->chs = NULL;
    res->len = 0;
    return res;
}

bool assignStr(Str *str, char *c) {
    if (str->chs) free(str->chs);
    unsigned int len = 0;
    char *p = c;
    // 求c串的长度
    while (*p) {
        ++len;
        ++p;
    }
    if (len == 0) {
        str->chs = NULL;
        str->len = 0;
        return true;
    }
    str->chs = (char *)malloc(sizeof(char) * (len + 1));
    if (str->chs == NULL) return false;
    p = c;
    for (int i = 0; i <= len; ++i, ++p) str->chs[i] = *p;
    str->len = len;
    return true;
}

unsigned int len(Str str) { return str.len; }

void printStr(Str *str) {
    if (str == NULL) {
        printf("NULL!");
        return;
    }
    printf("[%d]\t\t%s\n", str->len, str->chs);
}

/**
 * @brief 比较两个字符串
 *
 * @param str1
 * @param str2
 * @return 返回差异值，或长度差异
 */
int compareStr(Str str1, Str str2) {
    for (int i = 0; i < str1.len && i < str2.len; ++i) {
        if (str1.chs[i] != str2.chs[i]) {
            printf("diff>\t\tat [%d] %c | %c\n", i, str1.chs[i], str2.chs[i]);
            return str1.chs[i] - str2.chs[i];
        }
    }
    printf(">\t\tat len %d | %d\n", str1.len, str2.len);
    return str1.len - str2.len;
}

bool concatStr(Str str1, Str str2, Str *str) {
    if (str->chs) {
        free(str->chs);
        str->chs = NULL;
    }
    str->chs = (char *)malloc(sizeof(char) * (str1.len + str2.len + 1));
    if (str->chs == NULL) return false;
    int i = 0;
    for (; i < str1.len; ++i) str->chs[i] = str1.chs[i];
    for (int j = 0; j <= str2.len; ++j) str->chs[i + j] = str2.chs[j];
    str->len = str1.len + str2.len;
}

void freeStr(Str *str) {
    if (str->chs) {
        free(str->chs);
        str->chs = NULL;
    }
    str->len = 0;
}

Str *subStr(Str str, unsigned int start, unsigned int len) {
    Str *res = (Str *)malloc(sizeof(Str));
    freeStr(res);
    if (start >= str.len || len > str.len) return NULL;
    if (len == 0) return res;
    res->chs = (char *)malloc(sizeof(char) * (len + 1));
    int i = start, j = 0;
    for (; i < start + len; ++i, ++j) res->chs[j] = str.chs[i];
    res->chs[j] = '\0';
    res->len = len;
    return res;
}

unsigned int findStr(Str str, Str target) {
    int i = 0, j = 0, k = i;
    while (i <= str.len && j <= target.len) {
        if (str.chs[i] == target.chs[j]) {
            ++i;
            ++j;
        } else {
            j = 0;
            i = ++k;
        }
    }
    return j > target.len ? k : 0;
}

int *getKMPNext(Str str) {
    int i = 0, j = 0;
    int *next = (int *)malloc(sizeof(int) * str.len);
    next[0] = 0;
    while (i < str.len) {
        if (j == 0 || str.chs[i] == str.chs[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j - 1];
    }
    return next;
}

/**
 * @brief 优化方案
 *
 * @param str
 * @return int*
 */
int *getKMPnextVal(Str str) {
    int i = 0, j = 0;
    int *nextVal = (int *)malloc(sizeof(int) * str.len);
    nextVal[0] = 0;
    while (i < str.len) {
        if (j == 0 || str.chs[i] == str.chs[j]) {
            ++i;
            ++j;
            if (str.chs[i] != str.chs[j])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];
        } else
            j = nextVal[j];
    }
    return nextVal;
}

unsigned int KMP(Str str, Str substr) {
    int *next = getKMPnextVal(substr);
    int i = 0, j = 0;
    while (i < str.len && j < substr.len) {
        if (j == 0 || str.chs[i] == substr.chs[j]) {
            ++i;
            ++j;
        } else
            j = next[j - 1];
    }
    if (j >= substr.len)
        return i - substr.len;
    else
        return 0;
}