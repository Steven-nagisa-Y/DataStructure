#include <stdio.h>
#include <stdlib.h>
#define MAX 512

typedef char datatype;

typedef struct Huffman {
    datatype val;
    int weight;
    struct Huffman *left;
    struct Huffman *right;
} TreeNode;

typedef struct Set {
    TreeNode **data;
    int n;
} Set;

Set *initSet(datatype a[], int b[], int n) {
    Set *set = (Set *)malloc(sizeof(Set));
    set->data = (TreeNode **)malloc(sizeof(TreeNode **) * MAX);
    set->n = 0;
    for (int i = 0; i < n; ++i) {
        TreeNode *item = (TreeNode *)malloc(sizeof(TreeNode));
        item->val = a[i];
        item->weight = b[i];
        item->left = NULL;
        item->right = NULL;
        set->data[i] = item;
        ++set->n;
    }
    return set;
}

void sortSet(Set *set) {
    if (set->n < 2) return;
    TreeNode *tmp;
    for (int i = 0; i < set->n - 1; ++i) {
        for (int j = 0; j < set->n - i - 1; ++j) {
            if (set->data[j]->weight < set->data[j + 1]->weight) {
                tmp = set->data[j];
                set->data[j] = set->data[j + 1];
                set->data[j + 1] = tmp;
            }
        }
    }
}

void countChar(char *s, char *a, int *b, int *n) {
    int i = 0;
    int tmp[60];
    for (int j = 0; j < 60; ++j) {
        tmp[j] = 0;
    }
    while (s[i] != '\0') {
        ++tmp[s[i] - 'A'];
        ++i;
    }
    i = 0;
    for (int j = 0; j < 60; ++j) {
        if (tmp[j] != 0) {
            a[i] = j + 'A';
            b[i] = tmp[j];
            printf("%c:%d\n", a[i], b[i]);
            ++i;
        }
    }
    *n = i;
}

void buildHuffan(Set *set) {
    if (set->n == 1) return;
    sortSet(set);
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = '@';
    node->left = set->data[set->n - 1];
    node->right = set->data[set->n - 2];
    node->weight =
        set->data[set->n - 1]->weight + set->data[set->n - 2]->weight;
    --set->n;
    set->data[set->n - 1] = node;
    buildHuffan(set);
}

/**
 * @brief 按层遍历
 *
 * @param node
 */
void BFS(TreeNode *node) {
    int front = 0, rear = 0;
    TreeNode *queue[MAX];
    TreeNode *q;
    if (node == NULL) return;
    rear = (rear + 1) % MAX;
    queue[rear] = node;
    printf("Huffman Tree:");
    while (front != rear) {
        front = (front + 1) % MAX;
        q = queue[front];
        printf("\t%c(%d)", q->val, q->weight);
        if (q->left != NULL) {
            rear = (rear + 1) % MAX;
            queue[rear] = q->left;
        }
        if (q->right != NULL) {
            rear = (rear + 1) % MAX;
            queue[rear] = q->right;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter set> ");
    scanf("%d", &n);
    datatype s[n + 1];
    datatype a[n];
    int b[n];
    int i;
    for (i = 0; i < n; i++) {
        datatype tmp = getchar();
        if (tmp != ' ' && tmp != '\n')
            s[i] = tmp;
        else
            s[i] = getchar();
    }
    s[n] = '\0';
    countChar(s, a, b, &n);
    Set *set = initSet(a, b, n);
    buildHuffan(set);
    BFS(set->data[0]);
    return 0;
}
