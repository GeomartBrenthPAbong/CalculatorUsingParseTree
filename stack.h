#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct StackNode {
    struct StackNode *m_next_node;
    struct StackNode *m_prev_node;

    ParseTreeNode *m_data;
};

typedef struct StackNode StackNode;

StackNode *createStackNode(ParseTreeNode *p_data);

void initializeStack();

void push(ParseTreeNode *p_data);
ParseTreeNode *pop();

int getStackSize();
bool isStackEmpty();

#endif
