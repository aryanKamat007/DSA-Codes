//binary
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node *NODE;

NODE create(int num)
{
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = num;
   newnode->left = NULL;
   newnode->right = NULL;

   return newnode;
}

NODE insert(NODE root, int num)
{
    if (root == NULL)
    {
        return create(num);
    }
    if (num<root->data)
    {
         root->left = insert(root->left, num);
    }
    else if (num>root->data)
    {
         root->right = insert(root->right, num);
    }
    return root;
}

NODE iopred(NODE root)
{
   root=root->left;
   while(root->right!=NULL)
   {
       root=root->right;
   }
   return root;
}

NODE deletes(NODE root, int k)
{
    NODE ip;
    if(root == NULL)
    return root;

    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(k<root->data)
    {
        root->left=deletes(root->left,k);
    }
    else if(k>root->data)
    {
        root->right=deletes(root->right,k);
    }
    else{
        ip=iopred(root);
        root->data=ip->data;
        root->left=deletes(root->left,ip->data);
    }
    return  root;
}
void inorder(NODE root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d -> ", root->data);
  inorder(root->right);
}

void preorder(NODE root) {
  if (root == NULL) return;
  printf("%d -> ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(NODE root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d -> ", root->data);

}

int main()
{
    NODE root=NULL;
    int ch,n,key;
    while(1)
    {
    printf("BINARY TREE LIST\nSelect any option\n 1.Insert 2.Delete 3.display 4.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            {printf("Enter number to be inserted\n");
            scanf("%d",&n);
            root=insert(root,n);
             break;
            }

        case 2:
             {printf("Enter number to be deleted\n");
            scanf("%d",&key);
            root=deletes(root,key);
            break;
            }
        case 3:
            {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");

                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");

                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");

                printf("AVL Tree \n ");
                printLevelOrder(root);
                break;
            }
        case 4:
            {
                exit(0);
            }
    }
    }
    return 0;
}
