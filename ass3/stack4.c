Write a C program to convert infix expression into postfix form and evaluate it.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Function prototypes
void initStack(Stack* s);
int isEmpty(Stack* s);
int peek(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove the newline character from the input
    infix[strcspn(infix, "\n")] = '\0';

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Peek at the top element of the stack
int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = value;
    }
}

// Pop an element from the stack
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return -1;
}

// Get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

// Convert infix to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int k = 0; // Index for postfix array
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {  // If character is an operand
            postfix[k++] = ch;
        }
        else if (ch == '(') {  // If character is '('
            push(&stack, ch);
        }
        else if (ch == ')') {  // If character is ')'
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop '(' from stack
        }
        else {  // If character is an operator
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    
    // Pop any remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    
    postfix[k] = '\0';  // Null terminate the postfix expression
}

// Evaluate the postfix expression
int evaluatePostfix(char* postfix) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isdigit(ch)) {  // If the character is a digit, push to stack
            push(&stack, ch - '0');
        }
        else {  // If the character is an operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            
            switch (ch) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < val2; i++) {
                        result *= val1;
                    }
                    push(&stack, result);
                    break;
                }
            }
        }
    }
    
    return pop(&stack);  // The result is the only element left in the stack
}