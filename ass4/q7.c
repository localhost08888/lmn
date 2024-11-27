to implement Multiple Queues using single array


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Total size of the array
#define NUM_QUEUES 3 // Number of queues

typedef struct {
    int data[MAX_SIZE];
    int front[NUM_QUEUES];
    int rear[NUM_QUEUES];
    int size[NUM_QUEUES];
} MultipleQueues;

void init(MultipleQueues *mq) {
    for (int i = 0; i < NUM_QUEUES; i++) {
        mq->front[i] = -1;
        mq->rear[i] = -1;
        mq->size[i] = 0;
    }
}

int isFull(MultipleQueues *mq, int queueNum) {
    return mq->size[queueNum] == MAX_SIZE / NUM_QUEUES;
}

int isEmpty(MultipleQueues *mq, int queueNum) {
    return mq->size[queueNum] == 0;
}

void enqueue(MultipleQueues *mq, int queueNum, int value) {
    if (isFull(mq, queueNum)) {
        printf("Queue %d is full!\n", queueNum);
        return;
    }
    int index = (queueNum * (MAX_SIZE / NUM_QUEUES)) + mq->rear[queueNum] + 1;
    if (mq->rear[queueNum] == (MAX_SIZE / NUM_QUEUES) - 1) {
        mq->rear[queueNum] = -1;
    }
    mq->data[index] = value;
    mq->rear[queueNum] = (mq->rear[queueNum] + 1) % (MAX_SIZE / NUM_QUEUES);
    if (mq->front[queueNum] == -1) {
        mq->front[queueNum] = 0;
    }
    mq->size[queueNum]++;
}

int dequeue(MultipleQueues *mq, int queueNum) {
    if (isEmpty(mq, queueNum)) {
        printf("Queue %d is empty!\n", queueNum);
        return -1;
    }
    int index = (queueNum * (MAX_SIZE / NUM_QUEUES)) + mq->front[queueNum];
    int value = mq->data[index];
    mq->front[queueNum] = (mq->front[queueNum] + 1) % (MAX_SIZE / NUM_QUEUES);
    mq->size[queueNum]--;
    if (mq->size[queueNum] == 0) {
        mq->front[queueNum] = mq->rear[queueNum] = -1;
    }
    return value;
}

void display(MultipleQueues *mq, int queueNum) {
    if (isEmpty(mq, queueNum)) {
        printf("Queue %d is empty!\n", queueNum);
        return;
    }
    int i = mq->front[queueNum];
    printf("Queue %d: ", queueNum);
    while (i != mq->rear[queueNum]) {
        printf("%d ", mq->data[i]);
        i = (i + 1) % (MAX_SIZE / NUM_QUEUES);
    }
    printf("%d\n", mq->data[mq->rear[queueNum]]);
}

int main() {
    MultipleQueues mq;
    init(&mq);

    int choice, queueNum, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue number (0, 1, 2): ");
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&mq, queueNum, value);
                break;
            case 2:
                printf("Enter queue number (0, 1, 2): ");
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                value = dequeue(&mq, queueNum);
                if (value != -1) {
                    printf("Dequeued value from queue %d: %d\n", queueNum, value);
                }
                break;
            case 3:
                printf("Enter queue number (0, 1, 2): ");
                scanf("%d", &queueNum);
                if (queueNum < 0 || queueNum >= NUM_QUEUES) {
                    printf("Invalid queue number!\n");
                    break;
                }
                display(&mq, queueNum);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}