#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength(char *string)
{
    int length;
    for (length = 0; string[length] != '\0'; ++length)
        ;

    return length;
}

void readLinesFromFile(char lines[10][100], int *numLines)
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file input.txt");
        return;
    }
    char line[100];
    while (*numLines < 10 && fgets(line, 100, file) != NULL)
    {
        strncpy(lines[*numLines], line, 100);
        (*numLines)++;
    }
    fclose(file);
}

void writeLinesToFile(char lines[10][100], int *numLines)
{
    FILE *file = fopen("input.txt", "w");
    char line[100];

    while (*numLines < 10)
    {
        fprintf(file, "%s ", *lines);
        *lines++;
        (*numLines)++;
    }
    fclose(file);
}

void searchAndReplace(char *pattern, char *text, char *replacement)
{
    int n = stringLength(text);
    int m = stringLength(pattern);
    int o = stringLength(replacement);
    int k = 0, status, l;
    for (int i = 0; i < n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            status = 0;
            if (text[i + j] != pattern[j])
            {
                status = 1;
                break;
            }
        }
        if (status == 0)
        {
            l = i;
            while (k != o)
            {
                text[l] = replacement[k];
                l++;
                k++;
            }
            while (k != m)
            {
                text[l] = ' ';
                l++;
                k++;
            }
        }

        if (j == m)
            printf("%s\n", text);
    }
}

int main()
{
    char lines[10][100];
    int numLines = 0;
    char pattern[10];
    char replacement[10];

    printf("Reading from the file\n");
    readLinesFromFile(lines, &numLines);

    printf("Enter the word you want to search in the file: ");
    scanf("%s", pattern);
    printf("Enter the word you want to replace: ");
    scanf("%s", replacement);

    for (int i = 0; i < 10; i++)
    {
        searchAndReplace(pattern, lines[i], replacement);
    }

    writeLinesToFile(lines, &numLines);

    return 0;
}
