#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 255

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

/**
 * @brief 初始化变长串
 *
 * @return Str* 返回串的首地址
 */
Str *initStr() {
    Str *res = (Str *)malloc(sizeof(Str));
    res->chs = NULL;
    res->len = 0;
    return res;
}

/**
 * @brief 为串赋值
 *
 * @param str 变长串的首地址
 * @param c 被赋值的字符串
 * @return true 成功
 * @return false 失败
 */
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

/**
 * @brief 返回串的长度
 *
 * @param str 串
 * @return unsigned int 长度
 */
unsigned int len(Str str) { return str.len; }

/**
 * @brief 打印串长和串
 *
 * @param str 串
 */
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

/**
 * @brief 拼接两个字符串
 *
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @param str 拼接后的字符串
 * @return true 成功
 * @return false 失败
 */
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

/**
 * @brief 清空字符串
 *
 * @param str 需要被清空的字符串首地址
 */
void freeStr(Str *str) {
    if (str->chs) {
        free(str->chs);
        str->chs = NULL;
    }
    str->len = 0;
}

/**
 * @brief 求主串的子串
 *
 * @param str 主串
 * @param start 开始下标
 * @param len 子串长度
 * @return Str* 字串的首地址
 */
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

/**
 * @brief 简单查找匹配子串
 *
 * @param str 主串
 * @param target 子串
 * @return int 匹配的位置，未匹配为-1
 */
int findStr(Str str, Str target) {
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
    return j > target.len ? k : -1;
}

/**
 * @brief 获得KMP子串最长重复前后缀
 *
 * @param str 子串
 * @return int* 最长前后缀数组首地址，长度为[0]
 */
int *getKMPNext(Str str) {
    if (str.len == 1) {
        int *next = (int *)malloc(sizeof(int));
        next[0] = 0;
        return next;
    } else if (str.len == 0)
        return NULL;

    int i = 1, j = 0;
    int *next = (int *)malloc(sizeof(int) * (str.len));
    // next数组从1开始，next[0]为长度
    next[0] = str.len;
    next[1] = 0;
    while (i < str.len) {
        if (j == 0 || str.chs[i - 1] == str.chs[j - 1]) {
            ++i;
            ++j;
            next[i] = j;

        } else
            j = next[j];
    }
    return next;
}

/**
 * @brief 获得KMP子串最长重复前后缀优化方案
 *
 * @param str 子串
 * @return int* 最长前后缀数组首地址，长度为[0]
 */
int *getKMPnextVal(Str str) {
    if (str.len == 1) {
        int *next = (int *)malloc(sizeof(int));
        next[0] = 0;
        return next;
    } else if (str.len == 0)
        return NULL;

    int i = 1, j = 0;
    int *nextVal = (int *)malloc(sizeof(int) * str.len);
    nextVal[0] = str.len;
    nextVal[1] = 0;
    while (i < str.len) {
        if (j == 0 || str.chs[i - 1] == str.chs[j - 1]) {
            ++i;
            ++j;
            if (str.chs[i - 1] != str.chs[j - 1])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];
        } else
            j = nextVal[j];
    }
    return nextVal;
}

/**
 * @brief 快速匹配算法KMP
 *
 * @param str 主串
 * @param substr 子串
 * @return int 匹配位置，未匹配则返回-1
 */
int KMP(Str str, Str substr) {
    int *next = getKMPnextVal(substr);
    int i = 1, j = 1;
    while (i <= str.len && j <= substr.len) {
        if (j == 0 || str.chs[i - 1] == substr.chs[j - 1]) {
            ++i;
            ++j;
        } else
            j = next[j];
    }
    if (j > substr.len)
        return i - substr.len;
    else
        return -1;
}