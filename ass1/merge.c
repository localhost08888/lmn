#include <stdio.h>

int step_count_asc = 0, swap_count_asc = 0, comp_count_asc = 0;
int step_count_desc = 0, swap_count_desc = 0, comp_count_desc = 0;

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mergeAsc(int A[], int mid, int low, int high) {
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        comp_count_asc++;
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
        step_count_asc++;
    }

    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
        step_count_asc++;
    }

    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
        step_count_asc++;
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
        swap_count_asc++;
    }
}

void mergeDesc(int A[], int mid, int low, int high) {
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        comp_count_desc++;
        if (A[i] > A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
        step_count_desc++;
    }

    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
        step_count_desc++;
    }

    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
        step_count_desc++;
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
        swap_count_desc++;
    }
}

void mergeSortAsc(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSortAsc(A, low, mid);
        mergeSortAsc(A, mid + 1, high);
        mergeAsc(A, mid, low, high);
    }
}

void mergeSortDesc(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSortDesc(A, low, mid);
        mergeSortDesc(A, mid + 1, high);
        mergeDesc(A, mid, low, high);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int A[n], B[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }

    printf("\nArray before sorting:\n");
    printArray(A, n);

    mergeSortAsc(A, 0, n - 1);
    printf("\nArray after sorting in ascending order:\n");
    printArray(A, n);
    printf("Step count (asc): %d\nSwap count (asc): %d\nComparison count (asc): %d\n", step_count_asc, swap_count_asc, comp_count_asc);

    mergeSortDesc(B, 0, n - 1);
    printf("\nArray after sorting in descending order:\n");
    printArray(B, n);
    printf("Step count (desc): %d\nSwap count (desc): %d\nComparison count (desc): %d\n", step_count_desc, swap_count_desc, comp_count_desc);

    return 0;
}