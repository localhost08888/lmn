#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort for a specific digit place (e.g., units, tens, hundreds)
void countingSort(int arr[], int n, int place) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit at the current place
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Update count[i] to store cumulative counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted values back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output); // Free dynamically allocated memory
}

// Radix Sort implementation
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort for each digit place (1s, 10s, 100s, etc.)
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the Radix Sort
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
