#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct LLIST {
    int data;
    struct LLIST *next;
} LNODE;

// Function to create a linked list
LNODE* create(LNODE *head) {
    LNODE *curr;
    int i, nodes;

    printf("How many nodes to create?: ");
    scanf("%d", &nodes);

    head = (LNODE *)malloc(sizeof(LNODE));
    if (!head) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter the data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    curr = head;

    for (i = 1; i < nodes; i++) {
        curr->next = (LNODE *)malloc(sizeof(LNODE));
        if (!curr->next) {
            printf("Memory allocation failed!\n");
            return head;
        }
        curr = curr->next;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &curr->data);
        curr->next = NULL;
    }

    return head;
}

// Function to insert a node at a specific position
LNODE* insert(LNODE *head, int pos) {
    LNODE *newnode, *curr = head;
    int i;

    newnode = (LNODE *)malloc(sizeof(LNODE));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return head;
    }

    printf("Enter the data for the new node: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    for (i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return head;
    }

    newnode->next = curr->next;
    curr->next = newnode;

    return head;
}

// Function to delete a node at a specific position
LNODE* deleteNode(LNODE *head, int pos) {
    LNODE *temp, *curr = head;
    int i;

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    for (i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    temp = curr->next;
    curr->next = temp->next;
    free(temp);

    return head;
}

// Function to display the linked list
void display(LNODE *head) {
    LNODE *curr = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function for menu-driven operations
int main() {
    LNODE *head = NULL;
    int choice, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = create(head);
                break;
            case 2:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                head = insert(head, pos);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                head = deleteNode(head, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}