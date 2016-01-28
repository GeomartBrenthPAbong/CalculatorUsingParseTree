#define NULL 0
#include "token.h"
#include "parse_tree_node.h"
#include "parse_tree_traversal.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

ParseTreeNode *g_root_node = NULL;
ParseTreeNode *g_current_node = NULL;

void  initializeTree(ParseTreeNode* p_root_node){
    g_root_node = p_root_node;
    g_current_node = p_root_node;
}


void setLeftChild(ParseTreeNode* p_left_node){
    if(NULL == g_current_node)
        return;

    g_current_node->m_left_child = p_left_node;
}

void setRightChild(ParseTreeNode* p_right_node){
    if(NULL == g_current_node)
        return;

    g_current_node->m_right_child = p_right_node;
}

ParseTreeNode* getLeftChild(){
    if(NULL == g_current_node)
        return NULL;

    return g_current_node->m_left_child;
}

ParseTreeNode* getRightChild(){
    if(NULL == g_current_node)
        return NULL;

    return g_current_node->m_right_child;
}

ParseTreeNode* getCurrentNode(){
    return g_current_node;
}

void gotoLeftChild(){
    if(NULL == g_current_node)
        return;

    g_current_node = g_current_node->m_left_child;
}

void gotoRightChild(){
    if(NULL == g_current_node)
        return;

    g_current_node = g_current_node->m_right_child;
}

void gotoRootNode(){
    g_root_node = g_root_node;
}

bool hasLeftChild(){
    return NULL != g_current_node && NULL != g_current_node->m_left_child;
}

bool hasRightChild(){
    return NULL != g_current_node && NULL != g_current_node->m_right_child;
}

bool isValidNode(){
    return NULL != g_current_node;
}

void store(Token* p_token){
    if(NULL == g_current_node)
        return;

    g_current_node->m_token = p_token;
}

Token* getData(){
    if(NULL == g_current_node)
        return NULL;

    return g_current_node->m_token;
}

void deleteTreeFunc(ParseTreeNode* p_runner_node){
    free(p_runner_node);
    p_runner_node = NULL;
}

void deleteTree(){
    postOrderTraversal(g_root_node, &deleteTreeFunc);
    g_root_node = NULL;
    g_current_node = NULL;
}

