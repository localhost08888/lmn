1.Towers of Hanoi problem
2. Power of x to the n
3. Fibonacci series

#include <stdio.h>

// Function prototypes
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod);
int power(int x, int n);
int fibonacci(int n);

int main() {
    int choice, n, x;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Solve Towers of Hanoi\n");
        printf("2. Calculate power of x^n\n");
        printf("3. Calculate nth Fibonacci number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Towers of Hanoi
                printf("Enter the number of disks for Towers of Hanoi: ");
                scanf("%d", &n);
                printf("The sequence of moves are:\n");
                towerOfHanoi(n, 'A', 'C', 'B');  // A, B, C are rod names
                break;
            case 2:
                // Calculate power of x^n
                printf("Enter the base number (x): ");
                scanf("%d", &x);
                printf("Enter the exponent (n): ");
                scanf("%d", &n);
                printf("%d raised to the power %d is: %d\n", x, n, power(x, n));
                break;
            case 3:
                // Fibonacci series
                printf("Enter the value of n to calculate Fibonacci: ");
                scanf("%d", &n);
                printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
                break;
            case 4:
                // Exit
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Recursive function for solving Towers of Hanoi
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);  // Move n-1 disks to auxiliary rod
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);  // Move nth disk
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);  // Move n-1 disks to destination rod
}

// Recursive function to calculate power x^n
int power(int x, int n) {
    if (n == 0) {
        return 1;  // Base case: x^0 = 1
    } else {
        return x * power(x, n - 1);  // Recursive case
    }
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base cases: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}