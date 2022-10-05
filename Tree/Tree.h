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
 * @brief 线索二叉树
 * Ltag, Rtag为标识域
 * Ltag = 0时表示left为子节点指针，Ltag = 1时为线索，指向结点的前驱
 * Rtag = 0时表示right为子节点指针， Rtag = 1时为线索，指向节点的后继
 * @param val Value
 * @param Ltag
 * @param Rtag
 * @param left
 * @param right
 */
typedef struct TagBinTree {
    valtype val;
    int Ltag, Rtag;
    struct TagBinTree *left;
    struct TagBinTree *right;
} TagTree;

/**
 * @brief 树
 *
 * @param val value
 * @param count number of children
 * @param children a array of children's pointer.
 */
typedef struct Tree {
    valtype val;
    struct Tree **children;
    int count;
} Tree;

/**
 * @brief Create a Tree object
 *
 * @param arr input array in level order
 * @param i start index, usually is 0
 * @param n max index, usually is array's length
 * @return TreeNode*
 */
TreeNode *initTree(valtype *arr, int i, int n) {
    if (i >= n) return NULL;
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = arr[i];
    newNode->left = initTree(arr, 2 * i + 1, n);
    newNode->right = initTree(arr, 2 * i + 2, n);
    return newNode;
}

/**
 * @brief Preorder read tree
 *
 * @param node
 */
void preorder(TreeNode *node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode *node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

void postorder(TreeNode *node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

int getDepth(TreeNode *node) {
    int LD, RD;
    if (node == NULL) return 0;
    LD = getDepth(node->left);
    RD = getDepth(node->right);
    return (LD > RD ? LD : RD) + 1;
}

#define maxSize 256  // 队列的最大长度
/**
 * @brief 按层遍历
 *
 * @param node
 */
void BFS(TreeNode *node) {
    int front = 0, rear = 0;
    TreeNode *queue[maxSize];
    TreeNode *q;
    if (node == NULL) return;
    rear = (rear + 1) % maxSize;
    queue[rear] = node;
    while (front != rear) {
        front = (front + 1) % maxSize;
        q = queue[front];
        printf("%d ", q->val);
        if (q->left != NULL) {
            rear = (rear + 1) % maxSize;
            queue[rear] = q->left;
        }
        if (q->right != NULL) {
            rear = (rear + 1) % maxSize;
            queue[rear] = q->right;
        }
    }
}

int LevelWidth(TreeNode *root, int level) {
    if (!root)
        return 0;
    else {
        if (level == 1) return 1;
        level = LevelWidth(root->left, level - 1) +
                LevelWidth(root->right, level - 1);
    }
    return level;
}

int getWidth(TreeNode *root) {
    int width, i;
    int w[maxSize];
    for (i = 0; i < maxSize; i++) w[i] = 0;
    if (!root)
        width = 0;
    else {
        for (i = 0; i <= getDepth(root); i++) w[i] = LevelWidth(root, i + 1);
    }
    i = 0;
    while (w[i]) {
        if (w[i] > width) width = w[i];
        ++i;
    }
    return width;
}

bool search(TreeNode *node, int val) {
    if (node == NULL) return false;
    if (node->val == val) return true;
    bool l = search(node->left, val);
    // 剪枝
    if (l == false) {
        bool r = search(node->right, val);
        return r;
    } else
        return l;
}

/**
 * @brief 前序遍历循环方法
 *
 * @param node
 */
void preorderLoop(TreeNode *node) {
    if (node == NULL) return;
    TreeNode *stack[maxSize];
    int top = -1;
    TreeNode *p;
    stack[++top] = node;
    while (top != -1) {
        p = stack[top--];
        printf("%d ", p->val);
        // 栈是先进后出，则应先右后左
        if (p->right != NULL) stack[++top] = p->right;
        if (p->left != NULL) stack[++top] = p->left;
    }
}

/**
 * @brief 中序遍历循环方法
 *
 * @param node
 */
void inorderLoop(TreeNode *node) {
    if (node == NULL) return;
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
            printf("%d ", p->val);
            p = p->right;
        }
    }
}

/**
 * @brief 后序遍历循环方法
 *
 * @param node
 */
void postorderLoop(TreeNode *node) {
    if (node == NULL) return;
    TreeNode *stack1[maxSize];
    int top1 = -1;
    TreeNode *stack2[maxSize];
    int top2 = -1;
    TreeNode *p = NULL;
    stack1[++top1] = node;
    while (top1 != -1) {
        p = stack1[top1--];
        stack2[++top2] = p;
        if (p->left != NULL) stack1[++top1] = p->left;
        if (p->right != NULL) stack1[++top1] = p->right;
    }
    while (top2 != -1) {
        p = stack2[top2--];
        printf("%d ", p->val);
    }
}

void inorderTag(TagTree *node, TagTree *pre) {
    if (node == NULL) return;
    inorderTag(node->left, pre);
    if (node->left == NULL) {
        node->left = pre;
        node->Ltag = 1;
    }
    if (pre != NULL && pre->right == NULL) {
        pre->right = node;
        pre->Rtag = 1;
    }
    pre = node;
    inorderTag(node->right, pre);
}

/**
 * @brief Create a tagged Tree object
 *
 * @param arr input array in level order
 * @param i start index, usually is 0
 * @param n max index, usually is array's length
 * @return TreeNode*
 */
TagTree *initTagTree(valtype *arr, int i, int n) {
    if (i >= n) return NULL;
    TagTree *newNode = (TagTree *)malloc(sizeof(TagTree));
    newNode->val = arr[i];
    newNode->left = initTagTree(arr, 2 * i + 1, n);
    newNode->right = initTagTree(arr, 2 * i + 2, n);
    return newNode;
}

void createInorderTag(TagTree *root) {
    TagTree *pre = NULL;
    if (root == NULL) return;
    inorderTag(root, pre);
    pre->right = NULL;
    pre->Rtag = 1;
}

TagTree *firstTagNode(TagTree *node) {
    TagTree *p = node;
    while (p->Ltag == 0) p = p->left;
    return p;
}

TagTree *lastTagNode(TagTree *node) {
    TagTree *p = node;
    while (p->Rtag == 0) p = p->right;
    return p;
}

TagTree *nextTagNode(TagTree *node) {
    TagTree *p = node;
    if (p->Rtag == 0)
        return firstTagNode(p->right);
    else
        return p->right;
}

TagTree *prevTagNode(TagTree *node) {
    TagTree *p = node;
    if (p->Ltag == 0)
        return lastTagNode(p->left);
    else
        return p->right;
}

void inorderTagTree(TagTree *root) {
    for (TagTree *p = firstTagNode(root); p != NULL; p = nextTagNode(p))
        printf("%d ", p->val);
}

void addBinTree(TreeNode *node) {
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
}

Tree *createTreeNode(int val) {
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->val = val;
    root->count = 0;
    root->children = NULL;
    return root;
}

void addTreeChildren(Tree *root, int *c, int n) {
    root->children = (Tree **)malloc(sizeof(Tree *) * n);
    root->count = n;
    for (int i = 0; i < n; ++i) {
        Tree *node = createTreeNode(c[i]);
        root->children[i] = node;
    }
}

void preorderTree(Tree *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    for (int i = 0; i < root->count; ++i) {
        preorderTree(root->children[i]);
    }
}

void postorderTree(Tree *root) {
    if (root == NULL) return;
    for (int i = 0; i < root->count; ++i) {
        postorderTree(root->children[i]);
    }
    printf("%d ", root->val);
}

/**
 * @brief 树转化为二叉树
 *
 * @param root 树根
 * @param node 初始二叉树节点
 */
void tree2binTree(Tree *root, TreeNode *node) {
    int i = 0, j = 0;
    TreeNode *p, *temp, *flag;
    flag = node;
    while (root->children[i] != NULL) {
        addBinTree(temp);
        temp->val = root->children[i]->val;
        p = flag;
        if (i == 0) {
            p->left = temp;
            p = p->left;
            flag = flag->left;
        } else {
            p->right = temp;
            p = p->right;
            flag = flag->right;
        }
        j = 0;
        while (root->children[i]->children[j] != NULL) {
            addBinTree(temp);
            temp->val = root->children[i]->children[j]->val;
            if (j == 0) {
                p->left = temp;
                p = p->left;
            } else {
                p->right = temp;
                p = p->right;
            }
            j++;
        }
        i++;
    }
}

/**
 * @brief 二叉树转化为树
 *
 * @param root 二叉树根
 * @param node 树
 */
void binTree2tree(TreeNode *root, Tree *node) {
    if (root == NULL) return;
}
