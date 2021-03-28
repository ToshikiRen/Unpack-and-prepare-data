#ifndef QUEUE_H_
#define QUEUE_H_
#include "utils.h"
#include "queue_node.h"

typedef struct queue
{
    queue_node *front, *rear;
} Queue;

void createQueue(Queue **queue);
void en(Queue *queue,char *data);
char *de(Queue * queue);
void deleteQueue(Queue *queue);
bool isEmptyQueue(Queue *queue);
#endif
