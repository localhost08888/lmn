#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a circular linked list
Node* create(Node *tail) {
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    i = 0;  // Declare i outside the loop
    for (; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;  // First node points to itself
        } else {
            newNode->next = tail->next; // New node points to the head
            tail->next = newNode;      // Tail points to the new node
            tail = newNode;            // Update the tail
        }
    }

    return tail;
}

// Function to display the circular linked list
void display(Node *tail) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = tail->next; // Start from the head
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(back to head)\n");
}

// Function to insert a node at a specific position
Node* insert(Node *tail, int pos, int data) {
    int i = 0; // Declare i outside the loop
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (tail == NULL) {
        newNode->next = newNode; // Single node points to itself
        return newNode;
    }

    Node *current = tail->next; // Start from the head
    if (pos == 1) { // Insert at the beginning
        newNode->next = current;
        tail->next = newNode;
    } else { // Insert at a specific position
        for (; i < pos - 2 && current != tail; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) { // Update tail if inserted at the end
            tail = newNode;
        }
    }

    return tail;
}

// Function to delete a node at a specific position
Node* delete(Node *tail, int pos) {
    int i = 0; // Declare i outside the loop
    if (tail == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node *current = tail->next, *prev = tail;

    if (pos == 1) { // Delete the head node
        if (tail == tail->next) { // Only one node
            free(tail);
            return NULL;
        }
        tail->next = current->next;
        free(current);
    } else { // Delete a specific node
        for (; i < pos - 1 && current != tail; i++) {
            prev = current;
            current = current->next;
        }

        if (current == tail) { // Update tail if deleting the last node
            prev->next = current->next;
            tail = prev;
        } else {
            prev->next = current->next;
        }
        free(current);
    }

    return tail;
}

int main() {
    Node *tail = NULL;
    int choice, pos, data;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tail = create(tail);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                tail = insert(tail, pos, data);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                tail = delete(tail, pos);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}