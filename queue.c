#define NULL 0
#include "parse_tree_node.h"
#include "queue.h"

#include <stdbool.h>
#include <stdlib.h>

QueueNode *g_q_first_node;
QueueNode *g_q_last_node;
int g_queue_size;

QueueNode *createQueueNode(ParseTreeNode *p_data){
    QueueNode *node = malloc(sizeof(QueueNode));
    node->m_next_node = NULL;
    node->m_data = p_data;

    return node;
}

void initializeQueue(){
    g_q_first_node = NULL;
    g_q_last_node = NULL;
    g_queue_size = 0;
}

void enqueue(ParseTreeNode *p_data){
    if(NULL == g_q_first_node){
        g_q_first_node = createQueueNode(p_data);
        g_q_last_node = g_q_first_node;
    }
    else{
        g_q_last_node->m_next_node = createQueueNode(p_data);
        g_q_last_node = g_q_last_node->m_next_node;
    }

    g_queue_size++;
}

ParseTreeNode* dequeue(){
    ParseTreeNode *data;
    QueueNode *old_first_node;

    if(NULL == g_q_first_node)
        return NULL;
    else if(g_q_first_node == g_q_last_node){
        data = g_q_first_node->m_data;

        free(g_q_first_node);
        g_q_first_node = NULL;
        g_q_last_node = NULL;

        g_queue_size--;

        return data;
    }

    data = g_q_first_node->m_data;
    old_first_node = g_q_first_node;
    g_q_first_node = g_q_first_node->m_next_node;

    free(old_first_node);
    old_first_node = NULL;

    g_queue_size--;

    return data;
}

int getQueueSize(){
    return g_queue_size;
}

bool isQueueEmpty(){
    return 0 == g_queue_size;
}
