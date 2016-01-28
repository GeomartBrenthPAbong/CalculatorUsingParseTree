#define NULL 0
#include "parse_tree_node.h"
#include "queue.h"
#include "stack.h"

#include<stdio.h>

void preOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*)){
    if(NULL == p_runner_node)
        return;

    p_processor(p_runner_node);
    preOrderTraversal(p_runner_node->m_left_child, p_processor);
    preOrderTraversal(p_runner_node->m_right_child, p_processor);
}

void inOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*)){
    if(NULL == p_runner_node)
        return;

    inOrderTraversal(p_runner_node->m_left_child, p_processor);
    p_processor(p_runner_node);
    inOrderTraversal(p_runner_node->m_right_child, p_processor);
}

void postOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*)){
    if(NULL == p_runner_node)
        return;

    postOrderTraversal(p_runner_node->m_left_child, p_processor);
    postOrderTraversal(p_runner_node->m_right_child, p_processor);
    p_processor(p_runner_node);
}

void BFS(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*)){
    ParseTreeNode *current_node;

    if(NULL == p_runner_node)
        return;

    initializeQueue();
    enqueue(p_runner_node);

    while(!isQueueEmpty()){
        current_node = dequeue();
        p_processor(current_node);

        if(NULL != current_node->m_left_child)
            enqueue(current_node->m_left_child);

        if(NULL != current_node->m_right_child)
            enqueue(current_node->m_right_child);
    }
}

void DFS(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*)){
    ParseTreeNode *current_node;

    if(NULL == p_runner_node)
        return;

    initializeStack();
    push(p_runner_node);

    while(!isStackEmpty()){
        current_node = pop();
        p_processor(current_node);

        if(NULL != current_node->m_right_child)
            push(current_node->m_right_child);

        if(NULL != current_node->m_left_child)
            push(current_node->m_left_child);
    }
}
