#include <stdio.h>

#include "Tree.h"

unsigned int n = 0;
void findKth(TreeNode *node, int k) {
    if (node == NULL) return;
    if (++n == k) {
        printf("Kth is %d", node->val);
        return;
    }
    findKth(node->left, k);
    findKth(node->right, k);
}

int main(int argc, char const *argv[]) {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    TreeNode *head = initTree(a, 0, 10);
    findKth(head, 5);
    return 0;
}
