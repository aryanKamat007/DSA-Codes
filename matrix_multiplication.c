void readmatrix(int (*a)[100], int n1, int m1);
void displaymatrix(int (*a)[100], int n1, int m1);
void matrixmult(int (*a)[100], int (*b)[100], int (*c)[100], int n1, int m2, int m1);

int main()
{
    int first[100][100], second[100][100], answer[100][100];

    int n1, m1, n2, m2;

    printf("Enter no of row and column for matrix 1\n");
    scanf("%d%d", &n1, &m1);
    printf("Enter no of row and column for matrix 2\n");
    scanf("%d%d", &n2, &m2);

    if(m1 == n2)
    {
        printf("Enter values of matrix 1\n");
        readmatrix(first, n1, m1);
        displaymatrix(first, n1, m1);

        printf("\nEnter Second matrix\n");
        readmatrix(second, n2, m2);
        displaymatrix(second, n2, m2);

        matrixmult(first, second, answer, n1, m2, m1);

        printf("Product of matrices\n");

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<m2; j++)
                printf("%d\t",*(*(answer + i) + j));
            printf("\n");
        }
    }
    else
    {
       printf("Invalid multiplication");
    }
    return 0;
}

void readmatrix(int (*a)[100], int n1, int m1)
{
    for (int row = 0; row < n1; row++)
    {
        for (int col = 0; col < m1; col++)
        {
            scanf("%d", &a[row][col]);
        }
    }
}

void displaymatrix(int (*a)[100], int n1, int m1)
{
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<m1; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void matrixmult(int (*a)[100], int (*b)[100], int (*c)[100], int n1, int m2, int m1)
{
    for (int row = 0; row < n1; row++)
    {
        for (int col = 0; col < m2; col++)
        {
            int sum = 0;
            for (int i = 0; i < m1; i++)
            {
                sum += a[row][i] * b[i][col];
            }
            c[row][col] = sum;
        }
    }
}
