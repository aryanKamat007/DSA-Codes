#include <stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, rows, columns, a[10][10], b[10][10], c = 1;



    printf("\nEnter the number of rows and columns  :  ");
    scanf("%d %d", &i, &j);
    if(i!=j){
        printf("Not a square matrix exiting.....");
        exit(0);
    }
    printf("\nEnter the matrix elements \n");
    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
        {
            scanf("%d", &a[rows][columns]);
        }
    }
    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
        {
            b[columns][rows] = a[rows][columns];
        }
    }

    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
        {
            if (a[rows][columns] != b[rows][columns])
            {
                c++;
                break;
            }
        }
    }
    if (c == 1)
    {
        printf("\n The Matrix is a Symmetric Matrix. ");
    }
    else
    {
        printf("\n The Matrix is Not a Symmetric Matrix. ");
    }
    return 0;
}