#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef int valtype;

/**
 * @brief 二叉树
 *
 */
typedef struct BinTree {
    valtype val;
    struct BinTree *left;
    struct BinTree *right;
} TreeNode;

/**
 * @brief 顺序查找
 *
 * @param a 查找序列
 * @param n 序列长度
 * @param x 目标值
 * @return int 目标位置 或 -1
 */
int LinearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == x) return i + 1;  // 此处返回自然序号
    }
    return -1;
}

/**
 * @brief 二分查找
 *
 * @param a 查找序列
 * @param n 序列长度
 * @param x 目标值
 * @return int 目标位置 或 -1
 */
int BinarySearch(int a[], int n, int x) {
    int mid;
    int low = 0, high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x)
            return mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

TreeNode *BST(TreeNode *node, valtype key) {
    if (node == NULL) return NULL;
    if (node->val == key) return node;
    if (node->val > key) return BST(node->left, key);
    if (node->val < key) return BST(node->right, key);
}

bool insertBST(TreeNode *root, valtype key) {
    if (root == NULL) {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->left = root->right = NULL;
        root->val = key;
        return true;
    }
    if (root->val == key) return false;
    if (root->val > key)
        return insertBST(root->left, key);
    else
        return insertBST(root->right, key);
}

TreeNode *buildBST(valtype a[], int n) {
    TreeNode *root = NULL;
    for (int i = 0; i < n; ++i) insertBST(root, a[i]);
}

bool delBST(TreeNode *root, valtype key) {}