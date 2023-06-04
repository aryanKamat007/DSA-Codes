#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct stack
{
    int data[SIZE];
    int top;
};

int isFull(struct stack *sptr)
{
    if (sptr->top == SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *sptr)
{
    if (sptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *sptr, int element)
{
    sptr->top++;
    sptr->data[sptr->top] = element;
}

int pop(struct stack *sptr)
{
    int element = sptr->data[sptr->top];
    sptr->top--;
    return element;
}

void display(struct stack *sptr, FILE *stackFile)
{
    if (sptr->top == -1)
        printf("STACK EMPTY\n");
    else
    {
        for (int i = sptr->top; i != -1; i--)
        {
            printf("%d ", sptr->data[i]);
            fprintf(stackFile, "%d ", sptr->data[i]);
        }
    }
}

int main()
{
    struct stack s, *sptr = &s;
    FILE *inputFile, *pushLog, *popLog, *operationFile, *stackFile;

    inputFile = fopen("inputfile.txt", "w");
    pushLog = fopen("push_log.txt", "w");
    popLog = fopen("pop_log.txt", "w");
    operationFile = fopen("operation.txt", "w");
    stackFile = fopen("stack_file.txt", "w");

    sptr->top = -1;
    int choice, element;
    int start = 1, end = 100;
    int numbers[SIZE];
    srand(time(0));
    printf("The random numbers generated are\n");
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = rand() % (end - start + 1) + start;
        fprintf(inputFile, "%d ", numbers[i]);
        printf("%d ", numbers[i]);
    }

    int k = 0;
    while (1)
    {
        printf("\nSTACK MENU\n");
        printf("1.PUSH 2.POP 3.DISPLAY 4:EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(sptr))
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("PUSHED ELEMENT IS = %d\n", numbers[k]);
                fprintf(operationFile, "%s %d\n", "pushed =", numbers[k]);
                fprintf(pushLog, "%d ", numbers[k]);
                push(sptr, numbers[k]);
                k++;
            }
            break;

        case 2:
            if (isEmpty(sptr))
            {
                printf("Stack underflow\n");
            }
            else
            {
                element = pop(sptr);
                fprintf(operationFile, "%s %d\n", "popped =", element);
                fprintf(popLog, "%d ", element);
                printf("POPPED ELEMENT IS = %d\n", element);
            }
            break;

        case 3:
            display(sptr, stackFile);
            break;

        case 4:
            fclose(inputFile);
            fclose(operationFile);
            fclose(pushLog);
            fclose(popLog);
            fclose(stackFile);
            exit(0);
            break;

        default:
            printf("INVALID CHOICE \n");
            break;
        }
    }
    return 0;
}
