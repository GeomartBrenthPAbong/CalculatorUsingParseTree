#define NULL 0
#include "token.h"
#include "parse_tree_node.h"
#include <stdlib.h>

ParseTreeNode* createParseTreeNode(Token* p_token){
    ParseTreeNode *node = malloc(sizeof(ParseTreeNode));
    node->m_left_child = NULL;
    node->m_right_child = NULL;

    node->m_token = p_token;

    return node;
}

