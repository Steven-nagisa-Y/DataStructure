#include <stdio.h>

#include "Tree.h"

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    TreeNode *head = initTree(a, 0, 16);
    printf("Preorder:\t");
    preorderLoop(head);
    printf("\nInorder:\t");
    inorderLoop(head);
    printf("\nPostorder:\t");
    postorderLoop(head);
    printf("\nBFS:\t\t");
    BFS(head);
    printf("\n");
    int depth = getDepth(head);
    printf("depth:\t\t%d\n", depth);
    int width = getWidth(head);
    printf("width:\t\t%d\n", width);
    bool ans = search(head, 8);
    printf("%d in tree?\t%d\n", 8, ans);
    // 树
    Tree *root = createTreeNode(0);
    int c1[] = {1, 2, 3, 4};
    int c2[] = {5, 6};
    int c3[] = {7, 8, 9};
    addTreeChildren(root, c1, 4);
    addTreeChildren(root->children[0], c2, 2);
    addTreeChildren(root->children[2], c3, 3);
    printf("Preorder Tree::\t");
    preorderTree(root);
    printf("\nPostorder Tree:\t");
    postorderTree(root);
    return 0;
}
