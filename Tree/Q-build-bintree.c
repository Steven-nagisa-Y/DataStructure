#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int *preorderLoad(TreeNode *node, int n) {
    if (node == NULL) return NULL;
    int *res = (int *)malloc(sizeof(int) * n);
    int i = 0;
    TreeNode *stack[maxSize];
    int top = -1;
    TreeNode *p;
    stack[++top] = node;
    while (top != -1) {
        p = stack[top--];
        res[i] = p->val;
        ++i;
        // 栈是先进后出，则应先右后左
        if (p->right != NULL) stack[++top] = p->right;
        if (p->left != NULL) stack[++top] = p->left;
    }
    return res;
}

int *inorderLoad(TreeNode *node, int n) {
    if (node == NULL) return NULL;
    int *res = (int *)malloc(sizeof(int) * n);
    int i = 0;
    TreeNode *stack[maxSize];
    int top = -1;
    TreeNode *p;
    p = node;
    while (top != -1 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->left;
        }
        if (top != -1) {
            p = stack[top--];
            res[i] = p->val;
            ++i;
            p = p->right;
        }
    }
    return res;
}

TreeNode *buildTree(int *pre, int *in, int pL, int pR, int iL, int iR) {
    TreeNode *s;
    int i;
    if (pL > pR) return NULL;
    s = (TreeNode *)malloc(sizeof(TreeNode));
    s->left = s->right = NULL;
    for (i = iL; i < iR; ++i) {
        if (in[i] == pre[pL]) break;
    }
    s->val = in[i];
    s->left = buildTree(pre, in, pL + 1, pL + i - iL, iL, i - 1);
    s->right = buildTree(pre, in, pL + i - iL + 1, pR, i + 1, iR);
    return s;
}

/**
 * @brief 由先序序列和中序序列构造二叉树
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[]) {
    int a[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    TreeNode *root = initTree(a, 0, 10);
    int *preorderArr = preorderLoad(root, 10);
    int *inorderArr = inorderLoad(root, 10);
    for (int i = 0; i < 10; ++i) printf("%d ", preorderArr[i]);
    printf("\n");
    for (int i = 0; i < 10; ++i) printf("%d ", inorderArr[i]);
    TreeNode *rebuild = buildTree(preorderArr, inorderArr, 0, 9, 0, 9);
    printf("\n");
    BFS(rebuild);
    return 0;
}
