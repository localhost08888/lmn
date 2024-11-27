#include <stdio.h>

// Function to sort the array in ascending order
void asc_selectionSort(int arr[], int n, int *steps, int *swaps, int *comps) {
    int min, i, j;
    *steps = *swaps = *comps = 0;

    for (i = 0; i < n - 1; i++) {
        min = i; // Assume the current index is the minimum
        (*steps)++;
        for (j = i + 1; j < n; j++) {
            (*comps)++; // Increment comparisons
            if (arr[j] < arr[min]) {
                min = j; // Update the index of the minimum element
            }
        }
        if (min != i) {
            // Swap arr[i] and arr[min]
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            (*swaps)++; // Increment swaps
        }
        (*steps)++;
    }
}

// Function to sort the array in descending order
void desc_selectionSort(int arr[], int n, int *steps, int *swaps, int *comps) {
    int max, i, j;
    *steps = *swaps = *comps = 0;

    for (i = 0; i < n - 1; i++) {
        max = i; // Assume the current index is the maximum
        (*steps)++;
        for (j = i + 1; j < n; j++) {
            (*comps)++; // Increment comparisons
            if (arr[j] > arr[max]) {
                max = j; // Update the index of the maximum element
            }
        }
        if (max != i) {
            // Swap arr[i] and arr[max]
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            (*swaps)++; // Increment swaps
        }
        (*steps)++;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, steps, swaps, comps;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], original[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    printf("Sorting in ascending order:\n");
    asc_selectionSort(arr, n, &steps, &swaps, &comps);
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Steps: %d, Swaps: %d, Comparisons: %d\n", steps, swaps, comps);

    // Reset array to original values
    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }

    printf("\nSorting in descending order:\n");
    desc_selectionSort(arr, n, &steps, &swaps, &comps);
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Steps: %d, Swaps: %d, Comparisons: %d\n", steps, swaps, comps);

    return 0;
}