to implement a circular queue using array. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5

typedef struct {
    char data[MAXSIZE][100];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

void enqueue(CircularQueue *q, char *str) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add \"%s\".\n", str);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    strcpy(q->data[q->rear], str);
    printf("Enqueued \"%s\".\n", str);
}

char* dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    char *str = q->data[q->front];
    if (q->front == q->rear) { // If the queue has only one element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAXSIZE;
    }
    return str;
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    do {
        printf("%s ", q->data[i]);
        i = (i + 1) % MAXSIZE;
    } while (i != (q->rear + 1) % MAXSIZE);
    printf("\n");
}

int main() {
    CircularQueue q;
    int choice;
    char str[100];
    char *removed;

    initQueue(&q);

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the string to enqueue: ");
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = '\0'; // Remove trailing newline
                enqueue(&q, str);
                break;

            case 2:
                removed = dequeue(&q);
                if (removed) {
                    printf("Dequeued \"%s\".\n", removed);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}