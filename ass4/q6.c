Write a C program to implement static DEQUE.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} DEQUE;

void initDeque(DEQUE *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(DEQUE *dq) {
    return (dq->rear + 1) % MAX_SIZE == dq->front;
}

int isEmpty(DEQUE *dq) {
    return dq->front == -1;
}

void addFront(DEQUE *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->data[dq->front] = value;
}

void addRear(DEQUE *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->data[dq->rear] = value;
}

int deleteFront(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return value;
}

int deleteRear(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int value = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return value;
}

void display(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque contents: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->data[dq->rear]);
}

int main() {
    DEQUE dq;
    initDeque(&dq);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Add Front\n");
        printf("2. Add Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at front: ");
                scanf("%d", &value);
                addFront(&dq, value);
                break;
            case 2:
                printf("Enter value to add at rear: ");
                scanf("%d", &value);
                addRear(&dq, value);
                break;
            case 3:
                value = deleteFront(&dq);
                if (value != -1)
                    printf("Deleted %d from front\n", value);
                break;
            case 4:
                value = deleteRear(&dq);
                if (value != -1)
                    printf("Deleted %d from rear\n", value);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}