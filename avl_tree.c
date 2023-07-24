#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};
typedef struct node* NODE;

NODE create(int num) {
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int calcheight(NODE root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int balance(NODE root) {
    int bf, l, r;
    if (root == NULL)
        return 0;
    return calcheight(root->left) - calcheight(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

NODE LL(NODE x) {
    NODE y = x->right;
    NODE b = y->left;
    y->left = x;
    x->right = b;
    x->height = max(calcheight(x->left), calcheight(x->right)) + 1;
    y->height = max(calcheight(y->left), calcheight(y->right)) + 1;
    return y;
}

NODE RR(NODE y) {
    NODE x = y->left;
    NODE b = x->right;
    x->right = y;
    y->left = b;
    x->height = max(calcheight(x->left), calcheight(x->right)) + 1;
    y->height = max(calcheight(y->left), calcheight(y->right)) + 1;
    return x;
}

NODE insert(NODE root, int num) {
    if (root == NULL)
        return create(num);
    if (num < root->data)
        root->left = insert(root->left, num);
    else if (num > root->data)
        root->right = insert(root->right, num);

    root->height = max(calcheight(root->left), calcheight(root->right)) + 1;
    int bf = balance(root);

    if (bf > 1 && num < root->left->data) {
        return RR(root);
    }
    if (bf < -1 && num > root->right->data) {
        return LL(root);
    }
    if (bf > 1 && num > root->left->data) {
        root->left = LL(root->left);
        return RR(root);
    }
    if (bf < -1 && num < root->right->data) {
        root->right = RR(root->right);
        return LL(root);
    }
    return root;
}

NODE iopred(NODE root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

NODE deletes(NODE root, int k) {
    NODE ip;
    if (root == NULL)
        return root;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    if (k < root->data) {
        root->left = deletes(root->left, k);
    } else if (k > root->data) {
        root->right = deletes(root->right, k);
    } else {
        ip = iopred(root);
        root->data = ip->data;
        root->left = deletes(root->left, ip->data);
    }

    root->height = max(calcheight(root->left), calcheight(root->right)) + 1;
    int bf = balance(root);

    if (bf > 1) {
        return RR(root);
    }
    if (bf < -1) {
        return LL(root);
    }
    if (bf > 1) {
        root->left = LL(root->left);
        return RR(root);
    }
    if (bf < -1) {
        root->right = RR(root->right);
        return LL(root);
    }

    return root;
}

void inorder(NODE root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

void preorder(NODE root) {
    if (root == NULL)
        return;
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);
}

int height(NODE node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

void printCurrentLevel(NODE root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d     ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(NODE root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        printf("\n");
    }
}

int main() {
    NODE root = NULL;
    int ch, n, key;
    while (1) {
        printf("BINARY TREE LIST\nSelect any option\n 1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                printf("Enter number to be inserted\n");
                scanf("%d", &n);
                root = insert(root, n);
                break;
            }

            case 2: {
                printf("Enter number to be deleted\n");
                scanf("%d", &key);
                root = deletes(root, key);
                break;
            }
            case 3: {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");

                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");

                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");

                printf("AVL Tree (Level Order): \n");
                printLevelOrder(root);
                break;
            }

            case 4: {
                exit(0);
            }
        }
    }
    return 0;
}
