#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int maxlen;
    int top;
    int *data;
} Stack;

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->maxlen - 1;
}

void printStack(Stack* stack) {
    printf("Printando Stack de %d elementos: \n", stack->top + 1);
    int counter = 0;
    while (counter <= stack->top) {
        printf("%d ", stack->data[counter]);
        counter++;
    }
    printf("\n");
}

void stackValue(int value, Stack* stack) {
    if (isFull(stack)) {
        printf("Sorry man, the stack is full. sad man\n");
    }
    stack->top = stack->top + 1;
    stack->data[stack->top] = value;
}

int popValue(Stack* stack) {
    if (isEmpty(stack)) {
        printf("We dont have values on stack man, what are you doing man\n");
        return -1;
    }
    // return stack.data[stack.top--];
    int removedValue = stack->data[stack->top];
    stack->top = stack->top - 1;
    return removedValue;
}

int getTopValue(Stack* stack) {
    return stack->data[stack->top];
}

void clearStack(Stack* stack) {
    stack->top = -1;
}

Stack *createStack(int maxLen){
    Stack *created = (Stack * ) malloc(sizeof(Stack));
    created->top = -1;
    created->maxlen = maxLen;
    created->data = (int * ) malloc(sizeof(int) * maxLen);
    return created;
}