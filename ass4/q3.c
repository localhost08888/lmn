to implement a queue of integers using linked list. 

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} NODE;

// Global pointers for the front and rear of the queue
NODE *front = NULL, *rear = NULL;

// Function to initialize the queue
void initQueue() {
    front = rear = NULL;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to add an element to the queue
void addq(int n) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        printf("Memory allocation failed. Unable to add %d.\n", n);
        return;
    }
    newNode->data = n;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Added %d to the queue.\n", n);
}

// Function to delete an element from the queue
int delq() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    }
    NODE *temp = front;
    int deletedData = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL; // Reset rear if the queue is empty
    }
    free(temp);
    return deletedData;
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    NODE *current = front;
    printf("Queue elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function (menu-driven program)
int main() {
    int choice, value;
    initQueue();

    do {
        printf("\nMenu:\n");
        printf("1. Add to Queue\n");
        printf("2. Delete from Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to add: ");
                scanf("%d", &value);
                addq(value);
                break;

            case 2:
                value = delq();
                if (value != -1) {
                    printf("Deleted %d from the queue.\n", value);
                }
                break;

            case 3:
                displayQueue();
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