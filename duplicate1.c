#include <stdio.h>

#define SIZE 25

int findDuplicates(int arr[], int size) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    
    return count;
}

int findMode(int arr[], int size) {
    int maxCount = 0;
    int mode = 0;
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    
    return mode;
}

int main() {
    int arr[SIZE];
    
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    int duplicateCount = findDuplicates(arr, SIZE);
    int mode = findMode(arr, SIZE);
    
    printf("Number of duplicate elements: %d\n", duplicateCount);
    printf("Mode: %d\n", mode);
    
    return 0;
}
