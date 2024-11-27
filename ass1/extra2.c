Write a program that accept employee name, age and salary into array and sort them in descending order of salary. [Hint: Use array of structure]

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

void sortEmployeesBySalary(Employee employees[], int n) {
    int i, j;
    Employee temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (employees[i].salary < employees[j].salary) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee employees[MAX_EMPLOYEES];

    printf("Enter details of the employees:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        getchar();
        printf("Enter name: ");
        fgets(employees[i].name, MAX_NAME_LENGTH, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Enter age: ");
        scanf("%d", &employees[i].age);

        printf("Enter salary: ");
        scanf("%f", &employees[i].salary);
    }

    sortEmployeesBySalary(employees, n);

    printf("\nEmployees sorted by salary in descending order:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return 0;
}