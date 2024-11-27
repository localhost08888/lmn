Write a C program to create linked list of strings. Display all strings containing same substring. (Accept substring from user.)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertNode(Node* head, char* data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display all strings containing a given substring
void displayMatchingStrings(Node* head, char* substring) {
    int found = 0;
    Node* temp = head;
    printf("Strings containing substring \"%s\":\n", substring);
    while (temp != NULL) {
        if (strstr(temp->data, substring) != NULL) {
            printf("%s\n", temp->data);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No strings contain the substring \"%s\".\n", substring);
    }
}

// Function to display all strings in the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Linked List of Strings:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;
    int n;
    char data[100];
    char substring[100];

    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume the newline character

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        printf("String %d: ", i + 1);
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0'; // Remove the newline character
        head = insertNode(head, data);
    }

    printf("\nEnter the substring to search for: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Remove the newline character

    printf("\n");
    displayList(head);
    printf("\n");
    displayMatchingStrings(head, substring);

    return 0;
}