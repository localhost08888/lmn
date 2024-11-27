#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly circular linked list node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Function to create a doubly circular linked list
Node* create(Node *tail) {
    int n, data, i = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = newNode->prev = NULL;

        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
    }

    return tail;
}

// Function to display the doubly circular linked list
void display(Node *tail) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = tail->next;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(back to head)\n");
}

// Function to insert a node at a specific position
Node* insert(Node *tail, int pos, int data) {
    int i = 1;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (tail == NULL) {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    Node *current = tail->next;
    if (pos == 1) { // Insert at the beginning
        newNode->next = current;
        newNode->prev = tail;
        tail->next = newNode;
        current->prev = newNode;
    } else { // Insert at a specific position
        for (; i < pos - 1 && current != tail; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;

        if (current == tail) { // Update tail if inserted at the end
            tail = newNode;
        }
    }

    return tail;
}

// Function to delete a node at a specific position
Node* delete(Node *tail, int pos) {
    int i = 1;

    if (tail == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node *current = tail->next;
    if (pos == 1) { // Delete the first node
        if (tail == tail->next) { // Only one node
            free(tail);
            return NULL;
        }
        tail->next = current->next;
        current->next->prev = tail;
        free(current);
    } else { // Delete a specific node
        for (; i < pos && current != tail; i++) {
            current = current->next;
        }

        if (current == tail) { // Update tail if deleting the last node
            tail = tail->prev;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    return tail;
}

int main() {
    Node *tail = NULL;
    int choice, pos, data;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create Doubly Circular Linked List\n");
        printf("2. Display Doubly Circular Linked List\n");
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