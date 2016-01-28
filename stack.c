#define NULL 0
#include "parse_tree_node.h"
#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

StackNode *g_s_first_node;
StackNode *g_s_last_node;
int g_stack_size;

StackNode *createStackNode(ParseTreeNode* p_data){
    StackNode *node = malloc(sizeof(StackNode));
    node->m_next_node = NULL;
    node->m_prev_node = NULL;
    node->m_data = p_data;

    return node;
}

void initializeStack(){
    g_s_first_node = NULL;
    g_s_last_node = NULL;
    g_stack_size = 0;
}

void push(ParseTreeNode *p_data){
    if(NULL == g_s_first_node){
        g_s_first_node = createStackNode(p_data);
        g_s_last_node = g_s_first_node;
    }
    else{
        g_s_last_node->m_next_node = createStackNode(p_data);
        g_s_last_node->m_next_node->m_prev_node = g_s_last_node;
        g_s_last_node = g_s_last_node->m_next_node;
    }

    g_stack_size++;
}


ParseTreeNode *pop(){
    ParseTreeNode *data;
    StackNode *old_last_node;

    if(NULL == g_s_first_node)
        return NULL;
    else if(g_s_first_node == g_s_last_node){
        data = g_s_first_node->m_data;

        free(g_s_first_node);
        g_s_first_node = NULL;
        g_s_last_node = NULL;

        g_stack_size--;

        return data;
    }

    data = g_s_last_node->m_data;
    old_last_node = g_s_last_node;
    g_s_last_node = g_s_last_node->m_prev_node;

    free(old_last_node);
    old_last_node = NULL;
    g_s_last_node->m_next_node = NULL;

    g_stack_size--;

    return data;
}

int getStackSize(){
    return g_stack_size;
}

bool isStackEmpty(){
    return 0 == g_stack_size;
}
