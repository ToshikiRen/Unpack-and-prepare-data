#ifndef QUEUE_NODE_H_
#define QUEUE_NODE_H_

typedef struct queue_node
{
    char *data;
    struct queue_node *next;
} queue_node;

queue_node *createQueueNode(char *data);
void deleteQueueNode(queue_node *oldNode);
#endif