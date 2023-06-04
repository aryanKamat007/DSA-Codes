#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node *insert_at_beg(struct node *);
struct node *insert_at_end(struct node *);
struct node *insert_at_position(struct node *, int, struct node *);
struct node *delete_at_beg(struct node *);
struct node *delete_at_end(struct node *);
struct node *delete_at_position(struct node *, int);
void display(struct node *);

struct node *newnode, *temp, *temp1;

int main()
{
    int ch, position;
    head = NULL;

    while (1)
    {

        printf("1) insert at beginning\n");
        printf("2) insert at the end\n");
        printf("3) insert at specific position\n");
        printf("4) delete from beginning\n");
        printf("5) delete from the end\n");
        printf("6) delete from specific position\n");
        printf("7) display linked list\n");
        printf("8) exit\n");

        printf("\n\n-> Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            head = insert_at_beg(newnode);
            break;

        case 2:
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            head = insert_at_end(newnode);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &position);
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            head = insert_at_position(head, position, newnode);
            break;

        case 4:
            if (head == NULL)
                printf("The linked list is empty---can't delete\n");
            else
                head = delete_at_beg(head);
            break;

        case 5:
            if (head == NULL)
                printf("The linked list is empty---can't delete\n");
            else
                head = delete_at_end(head);
            break;

        case 6:
            if (head == NULL)
                printf("The linked list is empty---can't delete\n");
            else
            {
                printf("Enter position: ");
                scanf("%d", &position);
                head = delete_at_position(head, position);
            }
            break;

        case 7:
            display(head);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}

struct node *insert_at_beg(struct node *newnode)
{
    if (head == NULL)
    {
        head = newnode;
        head->next = NULL;
        return head;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
}

struct node *insert_at_end(struct node *newnode)
{
    if (head == NULL)
    {
        head = newnode;
        head->next = NULL;
        return head;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        return head;
    }
}

struct node *insert_at_position(struct node *head, int position, struct node *newnode)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return head;
    }
    else if (position == 1)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else
    {
        temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (temp == NULL)
            {
                printf("Invalid position\n");
                return head;
            }
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
}

struct node *delete_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }
    else
    {
        temp = head;
        head = head->next;
        printf("Node deleted: %d\n", temp->data);
        free(temp);
        return head;
    }
}

struct node *delete_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Node deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return head;
    }
    else
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp1 = temp->next;
        temp->next = NULL;
        printf("Node deleted: %d\n", temp1->data);
        free(temp1);
        return head;
    }
}

struct node *delete_at_position(struct node *head, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return head;
    }
    else if (position == 1)
    {
        temp = head;
        head = head->next;
        printf("Node deleted: %d\n", temp->data);
        free(temp);
        return head;
    }
    else
    {
        temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (temp == NULL)
            {
                printf("Invalid position\n");
                return head;
            }
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Invalid position\n");
            return head;
        }

        temp1 = temp->next;
        temp->next = temp1->next;
        printf("Node deleted: %d\n", temp1->data);
        free(temp1);
        return head;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
