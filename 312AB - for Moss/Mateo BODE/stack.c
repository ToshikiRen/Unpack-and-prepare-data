#include "stack.h"

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (TreeNode**)malloc(sizeof(TreeNode*) * stack->capacity);
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, TreeNode* item) {
    if (isFull(stack)) {
        return;
    }
    stack->arr[++stack->top] = item;
}

TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

TreeNode* peek(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top];
}