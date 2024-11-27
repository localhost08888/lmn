add two polynomials using linked list. 

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the polynomial term
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial
Node* insertNode(Node* head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
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

// Function to display a polynomial
void displayPolynomial(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent > p2->exponent) {
            result = insertNode(result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            result = insertNode(result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            result = insertNode(result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertNode(result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertNode(result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int n1, n2, coeff, exp, i;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms (coefficient and exponent) in descending order of exponents:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d%d", &coeff, &exp);
        poly1 = insertNode(poly1, coeff, exp);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms (coefficient and exponent) in descending order of exponents:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d%d", &coeff, &exp);
        poly2 = insertNode(poly2, coeff, exp);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}



 multiply two polynomials. 

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a polynomial term
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial in sorted order
Node* insertTerm(Node* head, int coefficient, int exponent) {
    if (coefficient == 0) {
        return head;
    }
    Node* newNode = createNode(coefficient, exponent);
    if (head == NULL || head->exponent < exponent) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL && current->next->exponent >= exponent) {
        if (current->next->exponent == exponent) {
            current->next->coefficient += coefficient;
            free(newNode);
            return head;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to display the polynomial
void displayPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != NULL) {
        p2 = poly2;
        while (p2 != NULL) {
            int coefficient = p1->coefficient * p2->coefficient;
            int exponent = p1->exponent + p2->exponent;
            result = insertTerm(result, coefficient, exponent);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return result;
}

// Function to create a polynomial from user input
Node* createPolynomial() {
    Node* head = NULL;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int coefficient, exponent;
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coefficient, &exponent);
        head = insertTerm(head, coefficient, exponent);
    }
    return head;
}

// Main function
int main() {
    printf("Enter the first polynomial:\n");
    Node* poly1 = createPolynomial();
    printf("Enter the second polynomial:\n");
    Node* poly2 = createPolynomial();

    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    Node* result = multiplyPolynomials(poly1, poly2);

    printf("Resultant Polynomial after multiplication: ");
    displayPolynomial(result);

    return 0;
}