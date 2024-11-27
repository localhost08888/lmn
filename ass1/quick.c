#include <stdio.h>

int stepsAsc = 0, swapsAsc = 0, compsAsc = 0;
int stepsDesc = 0, swapsDesc = 0, compsDesc = 0;

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partitionAsc(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    stepsAsc++;
    do {
        while (i <= high && A[i] <= pivot) {
            i++;
            compsAsc++;
        }
        compsAsc++;
        while (A[j] > pivot) {
            j--;
            compsAsc++;
        }
        compsAsc++;
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            swapsAsc++;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    swapsAsc++;

    return j;
}

void quickSortAsc(int A[], int low, int high) {
    if (low < high) {
        int partitionIndex = partitionAsc(A, low, high);
        quickSortAsc(A, low, partitionIndex - 1);
        quickSortAsc(A, partitionIndex + 1, high);
        stepsAsc++;
    }
}

int partitionDesc(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    stepsDesc++;
    do {
        while (i <= high && A[i] >= pivot) {
            i++;
            compsDesc++;
        }
        compsDesc++;
        while (A[j] < pivot) {
            j--;
            compsDesc++;
        }
        compsDesc++;
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            swapsDesc++;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    swapsDesc++;

    return j;
}

void quickSortDesc(int A[], int low, int high) {
    if (low < high) {
        int partitionIndex = partitionDesc(A, low, high);
        quickSortDesc(A, low, partitionIndex - 1);
        quickSortDesc(A, partitionIndex + 1, high);
        stepsDesc++;
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

    printf("Array before sorting:\n");
    printArray(A, n);

    quickSortAsc(A, 0, n - 1);
    printf("Array after sorting in ascending order:\n");
    printArray(A, n);
    printf("Ascending Order - Steps: %d, Swaps: %d, Comparisons: %d\n", stepsAsc, swapsAsc, compsAsc);

    quickSortDesc(B, 0, n - 1);
    printf("Array after sorting in descending order:\n");
    printArray(B, n);
    printf("Descending Order - Steps: %d, Swaps: %d, Comparisons: %d\n", stepsDesc, swapsDesc, compsDesc);

    return 0;
}