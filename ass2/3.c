merge two sorted linked list.


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertNode(Node* head, int data) {
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

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeSortedLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeSortedLists(head1, head2->next);
    }
    return mergedHead;
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n1, n2, data;

    printf("Enter the number of elements in the first sorted linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first sorted linked list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        list1 = insertNode(list1, data);
    }

    printf("Enter the number of elements in the second sorted linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second sorted linked list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        list2 = insertNode(list2, data);
    }

    printf("First Sorted Linked List:\n");
    displayList(list1);

    printf("Second Sorted Linked List:\n");
    displayList(list2);

    Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted Linked List:\n");
    displayList(mergedList);

    return 0;
}