#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char data;
    struct Node *next;
} NODE;

typedef struct Stack {
    NODE *top;
} STACK;

void initStack(STACK *stk);
void push(STACK *stk, char item);
char pop(STACK *stk);
int isEmpty(STACK *stk);

#endif

-----------------------

#include "Stack.h"

void initStack(STACK *stk) {
    stk->top = NULL;
}

void push(STACK *stk, char item) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = item;
    newNode->next = stk->top;
    stk->top = newNode;
}

char pop(STACK *stk) {
    if (isEmpty(stk)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    NODE *temp = stk->top;
    char item = temp->data;
    stk->top = stk->top->next;
    free(temp);
    return item;
}

int isEmpty(STACK *stk) {
    return stk->top == NULL;
}

________________________

#include <stdio.h>
#include <string.h>
#include "Stack.h"

int isPalindrome(const char *str) {
    STACK stk;
    initStack(&stk);

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        push(&stk, str[i]);
    }

    for (int i = 0; i < length; i++) {
        if (str[i] != pop(&stk)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}