#include <stdio.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void read_input(char lines[MAX_LINES][MAX_LENGTH], int *numLines)
{
    printf("Enter text lines (maximum %d lines):\n", MAX_LINES);
    *numLines = 0;

    while (*numLines < MAX_LINES)
    {
        fgets(lines[*numLines], MAX_LENGTH, stdin);

        if (lines[*numLines][0] == '\n')
        {
            break;
        }

        (*numLines)++;
    }
}

void read_file(char lines[MAX_LINES][MAX_LENGTH], int *numLines, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file '%s'.\n", filename);
        return;
    }

    *numLines = 0;

    while (*numLines < MAX_LINES && fgets(lines[*numLines], MAX_LENGTH, file))
    {
        (*numLines)++;
    }

    fclose(file);
}

int findLongestLine(const char lines[MAX_LINES][MAX_LENGTH], int numLines)
{
    int longestLineIndex = 0;
    int longestLineLength = 0;

    for (int i = 0; i < numLines; i++)
    {
        int lineLength = 0;
        while (lines[i][lineLength] != '\n' && lines[i][lineLength] != '\0')
        {
            lineLength++;
        }

        if (lineLength > longestLineLength)
        {
            longestLineLength = lineLength;
            longestLineIndex = i;
        }
    }

    return longestLineIndex;
}

int main()
{
    char lines[MAX_LINES][MAX_LENGTH];
    int numLines;
    int longestLineIndex;

    read_input(lines, &numLines);

    longestLineIndex = findLongestLine(lines, numLines);

    if (numLines > 0)
    {
        printf("\nLines read from user input:\n");
        for (int i = 0; i < numLines; i++)
        {
            printf("%s", lines[i]);
        }

        printf("\nLongest line: %s", lines[longestLineIndex]);
    }

    char filename[100];
    printf("\nEnter filename to read lines from (empty to skip): ");
    scanf("%s", filename);

    if (filename[0] != '\0')
    {
        read_file(lines, &numLines, filename);

        longestLineIndex = findLongestLine(lines, numLines);

        if (numLines > 0)
        {
            printf("\nLines read from file '%s':\n", filename);
            for (int i = 0; i < numLines; i++)
            {
                printf("%s", lines[i]);
            }

            printf("\nLongest line: %s", lines[longestLineIndex]);
        }
    }

    return 0;
}