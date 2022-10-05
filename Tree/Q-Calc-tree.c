#include <stdio.h>

#include "Tree.h"

typedef char datatype;

int operate(int a, int b, char c) {
    switch (c) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            if (b != 0)
                return a / b;
            else
                return 0;
            break;
        default:
            break;
    }
}

int comp(TreeNode *node) {
    int a, b;
    if (node == NULL) return 0;
    if (node->left != NULL && node->right != NULL) {
        a = comp(node->left);
        b = comp(node->right);
        return operate(a, b, node->val);
    } else
        return node->val;
}
