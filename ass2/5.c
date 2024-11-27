Write a C program to reverse a string using static stack. (Create Stack.h file.) 

#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100

typedef struct Stack {
    char data[MAXSIZE];
    int top;
} STACK;

void initStack(STACK *stk);
void push(STACK *stk, char item);
char pop(STACK *stk);
int isEmpty(STACK *stk);

#endif
______________________

#include <stdio.h>
#include <string.h>
#include "Stack.h"

void initStack(STACK *stk) {
    stk->top = -1;
}

void push(STACK *stk, char item) {
    if (stk->top == MAXSIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stk->data[++stk->top] = item;
}

char pop(STACK *stk) {
    if (stk->top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stk->data[stk->top--];
}

int isEmpty(STACK *stk) {
    return stk->top == -1;
}

void reverseString(char str[]) {
    STACK stk;
    initStack(&stk);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&stk, str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&stk);
    }
}

int main() {
    char str[MAXSIZE];
    printf("Enter a string: ");
    fgets(str, MAXSIZE, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove trailing newline

    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}