*Write a C program to simulate recursion of following functions:
a. Factorial of n numbers
b. Power function*

#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;  // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1);  // Recursive case: n! = n * (n-1)!
    }
}

// Function to calculate power using recursion
int power(int x, int n) {
    if (n == 0) {
        return 1;  // Base case: x^0 = 1
    } else {
        return x * power(x, n - 1);  // Recursive case: x^n = x * x^(n-1)
    }
}

int main() {
    int n, x;

    // Factorial simulation
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    // Power simulation
    printf("Enter the base number (x): ");
    scanf("%d", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);
    printf("%d raised to the power %d is %d\n", x, n, power(x, n));

    return 0;
}