#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct QueueNode{
    struct QueueNode *m_next_node;

    ParseTreeNode *m_data;
};

typedef struct QueueNode QueueNode;

QueueNode *createQueueNode(ParseTreeNode *p_data);
ParseTreeNode* dequeue();

void initializeQueue();
void enqueue(ParseTreeNode *p_data);

int getQueueSize();
bool isQueueEmpty();


#endif
