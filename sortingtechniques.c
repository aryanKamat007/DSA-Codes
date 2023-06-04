#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort();
void selectionSort();

int main() {
    int lower, upper, count, num, i;
    float duration;
    clock_t start, end;
    FILE *file;

    printf("Enter lower and upper range: ");
    scanf("%d %d", &lower, &upper);

    printf("Enter count: ");
    scanf("%d", &count);

    file = fopen("inp.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    srand(time(0));
    printf("The random numbers are: \n");
    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
        printf("%d\n", num);
        fprintf(file, "%d ", num);
    }
    printf("\nNumbers have been printed to the file successfully.\n");
    fclose(file);

    start = clock();
    bubbleSort();
    end = clock();
    duration = (float)(end - start);
    printf("\nDuration for bubble sort: %f", duration);

    start = clock();
    selectionSort();
    end = clock();
    duration = (float)(end - start);
    printf("\nDuration for selection sort: %f", duration);

    return 0;
}

void bubbleSort() {
    int arr[100], i, n = 0, j, temp, s = 0;
    FILE *inputFile, *outputFile;

    inputFile = fopen("inp.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(0);
    }

    outputFile = fopen("out.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(0);
    }

    while (fscanf(inputFile, "%d", &arr[s]) == 1) {
        s++;
        n++;
    }

    for (s = 0; s < n; s++) {
        printf("\nNumbers in array: %d\t", arr[s]);
    }
    fclose(inputFile);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (s = 0; s < n; s++) {
        printf("\n\nSorted array: %d\t", arr[s]);
        fprintf(outputFile, "%d\t", arr[s]);
    }
    fclose(outputFile);
}

void selectionSort() {
    int arr[100], i, n = 0, j, temp, s = 0, x, r;
    FILE *inputFile, *outputFile;

    inputFile = fopen("inp.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(0);
    }

    outputFile = fopen("out.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(0);
    }

    while (fscanf(inputFile, "%d", &arr[s]) == 1) {
        s++;
        n++;
    }

    for (s = 0; s < n; s++) {
        printf("\nNumbers in array: %d\t", arr[s]);
    }
    fclose(inputFile);

    for (i = 0; i < n - 1; i++) {
        x = arr[i];
        for (j = i + 1; j < n; j++) {
            if (arr[j] < x) {
                x = arr[j];
                r = j;
            }
        }
        temp = arr[i];
        arr[i] = x;
        arr[r] = temp;
    }

    for (s = 0; s < n; s++) {
        printf("\n\nSorted array: %d\t", arr[s]);
        fprintf(outputFile, "%d\t", arr[s]);
    }
    fclose(outputFile);
}
