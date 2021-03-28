#ifndef STACK_NODE_H_
#define STACK_NODE_H_
#include "utils.h"

typedef struct stack_node
{
    char data;
    struct stack_node *next;
} stack_node;

stack_node *createStackNode(char data);

#endif