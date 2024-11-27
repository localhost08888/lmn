union, intersection operations on two sorted linked lists.

#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a node at the end of the linked list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to display a linked list
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to compute the union of two sorted linked lists
Node* findUnion(Node* head1, Node* head2) {
    Node* result = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            result = insertNode(result, head1->data);
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            result = insertNode(result, head2->data);
            head2 = head2->next;
        } else {
            result = insertNode(result, head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while (head1 != NULL) {
        result = insertNode(result, head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        result = insertNode(result, head2->data);
        head2 = head2->next;
    }
    return result;
}

// Function to compute the intersection of two sorted linked lists
Node* findIntersection(Node* head1, Node* head2) {
    Node* result = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        } else {
            result = insertNode(result, head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return result;
}

int main() {
    Node *head1 = NULL, *head2 = NULL;
    int n1, n2, i, data;

    printf("Enter the number of elements in the first sorted linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first sorted linked list:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &data);
        head1 = insertNode(head1, data);
    }

    printf("Enter the number of elements in the second sorted linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second sorted linked list:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &data);
        head2 = insertNode(head2, data);
    }

    printf("First Linked List: ");
    display(head1);
    printf("Second Linked List: ");
    display(head2);

    Node* unionList = findUnion(head1, head2);
    printf("Union of the two linked lists: ");
    display(unionList);

    Node* intersectionList = findIntersection(head1, head2);
    printf("Intersection of the two linked lists: ");
    display(intersectionList);

    return 0;
}