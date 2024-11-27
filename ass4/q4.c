to implement static ascending priority queue


#include <stdio.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE]; // Array to hold the elements
    int size;          // Number of elements in the queue
} PriorityQueue;

// Function to initialize the priority queue
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to check if the queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Function to check if the queue is full
int isFull(PriorityQueue *pq) {
    return pq->size == MAXSIZE;
}

// Function to add an element to the priority queue
void enqueue(PriorityQueue *pq, int value) {
    if (isFull(pq)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    // Insert the element at the correct position to maintain ascending order
    int i;
    for (i = pq->size - 1; i >= 0 && pq->data[i] > value; i--) {
        pq->data[i + 1] = pq->data[i];
    }
    pq->data[i + 1] = value;
    pq->size++;
    printf("Enqueued %d into the priority queue.\n", value);
}

// Function to remove the element with the highest priority (smallest value)
int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;
    return value;
}

// Function to display the priority queue
void displayQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}

// Main function (menu-driven program)
int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&pq, value);
                break;

            case 2:
                value = dequeue(&pq);
                if (value != -1) {
                    printf("Dequeued %d from the priority queue.\n", value);
                }
                break;

            case 3:
                displayQueue(&pq);
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