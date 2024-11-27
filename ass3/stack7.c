Write a C program to simulate recursion of Towers of Hanoi function


#include <stdio.h>

void towersOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towersOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The moves involved are:\n");
    towersOfHanoi(n, 'A', 'C', 'B');
    return 0;
}