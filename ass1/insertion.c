#include <stdio.h>

void asc_insertsort(int arr[], int n, int *steps, int *swaps, int *comps) {
    int i, j, key;
    *steps = *swaps = *comps = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        (*steps)++;
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
            (*swaps)++;
            (*comps)++;
        }
        if (j >= 0) (*comps)++;
        arr[j + 1] = key;
        (*steps)++;
    }
}

void desc_insertsort(int arr[], int n, int *steps, int *swaps, int *comps) {
    int i, j, key;
    *steps = *swaps = *comps = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        (*steps)++;
        for (j = i - 1; j >= 0 && key > arr[j]; j--) {
            arr[j + 1] = arr[j];
            (*swaps)++;
            (*comps)++;
        }
        if (j >= 0) (*comps)++;
        arr[j + 1] = key;
        (*steps)++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
    asc_insertsort(arr, n, &steps, &swaps, &comps);
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Steps: %d, Swaps: %d, Comparisons: %d\n", steps, swaps, comps);

    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }

    printf("\nSorting in descending order:\n");
    desc_insertsort(arr, n, &steps, &swaps, &comps);
    printf("Sorted array: ");
    printArray(arr, n);
    printf("Steps: %d, Swaps: %d, Comparisons: %d\n", steps, swaps, comps);

    return 0;
}