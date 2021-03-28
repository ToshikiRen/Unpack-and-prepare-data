#ifndef STACK_H_
#define STACK_H_
#include "stack_node.h"


typedef struct stack
{
    stack_node *head;
    int size;
}Stack;


void createStack(Stack **stack);
void deleteStack(Stack *stack);
void push(Stack *stack,char data);
char pop(Stack *stack);
bool isEmptyStack(Stack *stack);

#endif