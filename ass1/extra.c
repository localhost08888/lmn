Write a program that accept name of persons into array and sort them in alphabetical order


#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PERSONS 10

void sortNames(char names[][MAX_NAME_LENGTH], int n) {
    int i, j;
    char temp[MAX_NAME_LENGTH];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                // Swap names[i] and names[j]
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    // Array to hold names of persons
    char names[MAX_PERSONS][MAX_NAME_LENGTH];

    printf("Enter the names of the persons:\n");
    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        getchar();  // To consume the newline character left by previous input
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';  // Remove the newline character
    }

    // Sort the names alphabetically
    sortNames(names, n);

    printf("\nSorted list of names in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}