#include "stack.h"
#include "utils.h"

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    assert(isNotNull((void*)stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (TreeNode**)malloc(sizeof(TreeNode*) * stack->capacity);

    assert(isNotNull((void*)stack->arr));

    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isNotEmpty(Stack* stack){
    return !isEmpty(stack);
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