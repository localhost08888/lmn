Write a C program to convert infix expression into prefix form and evaluate it.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators and operands
typedef struct {
    int top;
    char arr[MAX];
} Stack;

// Function prototypes
void initStack(Stack *s);
int isEmpty(Stack *s);
char peek(Stack *s);
void push(Stack *s, char item);
char pop(Stack *s);
int precedence(char op);
void reverse(char *expr);
void infixToPrefix(char *infix, char *prefix);
int evaluatePrefix(char *prefix);

int main() {
    char infix[MAX], prefix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    
    // Remove newline character
    infix[strcspn(infix, "\n")] = '\0';

    // Convert infix to prefix
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    
    // Evaluate the prefix expression
    int result = evaluatePrefix(prefix);
    printf("Evaluation result: %d\n", result);

    return 0;
}

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Peek at the top element of the stack
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

// Push an element onto the stack
void push(Stack *s, char item) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = item;
    }
}

// Pop an element from the stack
char pop(Stack *s) {
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

// Reverse a string
void reverse(char *expr) {
    int len = strlen(expr);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = expr[i];
        expr[i] = expr[j];
        expr[j] = temp;
    }
}

// Infix to Prefix conversion
void infixToPrefix(char *infix, char *prefix) {
    Stack stack;
    initStack(&stack);
    int k = 0;  // Index for prefix array

    // Reverse the infix expression
    reverse(infix);

    // Infix to Postfix Conversion (Shunting Yard Algorithm)
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {  // If character is operand
            prefix[k++] = ch;
        } else if (ch == ')') {  // If character is ')'
            push(&stack, ch);
        } else if (ch == '(') {  // If character is '('
            while (!isEmpty(&stack) && peek(&stack) != ')') {
                prefix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop ')' from stack
        } else {  // If character is an operator
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(ch)) {
                prefix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&stack)) {
        prefix[k++] = pop(&stack);
    }

    prefix[k] = '\0';  // Null-terminate the prefix expression

    // Reverse the prefix expression
    reverse(prefix);
}

// Evaluate Prefix Expression
int evaluatePrefix(char *prefix) {
    Stack stack;
    initStack(&stack);

    // Process the prefix expression from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {  // If the character is a digit, push it to the stack
            push(&stack, ch - '0');
        } else {  // If the character is an operator
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
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