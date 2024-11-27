to implement Josephus problem.

#include <stdio.h>

void josephus(int n, int k) {
    int people[n];
    int i, j;

    for (i = 0; i < n; i++) {
        people[i] = i + 1;
    }

    int count = n;
    int pos = 0;

    printf("The order of elimination is: \n");

    while (count > 1) {
        pos = (pos + k - 1) % count;
        printf("%d ", people[pos]);

        for (i = pos; i < count - 1; i++) {
            people[i] = people[i + 1];
        }

        count--;
    }

    printf("\nThe last remaining person is: %d\n", people[0]);
}

int main() {
    int n, k;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    printf("Enter the step (k): ");
    scanf("%d", &k);

    josephus(n, k);

    return 0;
}