#include <stdio.h>

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble sort in ascending order with counts
void ascBubbleSort(int arr[], int n, int *stepCount, int *swapCount, int *compCount) {
    *stepCount = *swapCount = *compCount = 0;
    int i, j;  // Declare i and j outside the loops
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*compCount)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
            (*stepCount)++;
        }
    }
}

// Bubble sort in descending order with counts
void descBubbleSort(int arr[], int n, int *stepCount, int *swapCount, int *compCount) {
    *stepCount = *swapCount = *compCount = 0;
    int i, j;  // Declare i and j outside the loops
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*compCount)++;
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
            (*stepCount)++;
        }
    }
}

int main() {
    int n, i;  // Declare i outside the loops
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], ascArr[n], descArr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        ascArr[i] = descArr[i] = arr[i];  // Create copies of the array for separate sorting
    }

    int ascStep, ascSwap, ascComp;
    int descStep, descSwap, descComp;

    // Ascending Bubble Sort
    ascBubbleSort(ascArr, n, &ascStep, &ascSwap, &ascComp);
    printf("\nArray sorted in ascending order: ");
    printArray(ascArr, n);
    printf("Step count: %d, Swap count: %d, Comparison count: %d\n", ascStep, ascSwap, ascComp);

    // Descending Bubble Sort
    descBubbleSort(descArr, n, &descStep, &descSwap, &descComp);
    printf("\nArray sorted in descending order: ");
    printArray(descArr, n);
    printf("Step count: %d, Swap count: %d, Comparison count: %d\n", descStep, descSwap, descComp);

    return 0;
}