Here’s the implementation of a linear queue of strings using an array. Add , delete,exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
#define STRLEN 100

typedef struct {
    char data[MAXSIZE][STRLEN];
    int front;
    int rear;
} queue;

void initq(queue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

int isempty(queue *pq) {
    return pq->front == -1 || pq->front > pq->rear;
}

int isfull(queue *pq) {
    return pq->rear == MAXSIZE - 1;
}

void addq(queue *pq, char *str) {
    if (isfull(pq)) {
        printf("Queue is full. Cannot add more elements.\n");
        return;
    }
    if (pq->front == -1) {
        pq->front = 0;
    }
    strcpy(pq->data[++(pq->rear)], str);
    printf("Added \"%s\" to the queue.\n", str);
}

char *delq(queue *pq) {
    if (isempty(pq)) {
        printf("Queue is empty. Cannot delete an element.\n");
        return NULL;
    }
    return pq->data[(pq->front)++];
}

int main() {
    queue q;
    char str[STRLEN];
    int choice;
    char *removed;

    initq(&q);

    do {
        printf("\nMenu:\n");
        printf("1. ADD\n");
        printf("2. DELETE\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the string to add: ");
                fgets(str, STRLEN, stdin);
                str[strcspn(str, "\n")] = '\0'; // Remove trailing newline
                addq(&q, str);
                break;

            case 2:
                removed = delq(&q);
                if (removed) {
                    printf("Deleted \"%s\" from the queue.\n", removed);
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}