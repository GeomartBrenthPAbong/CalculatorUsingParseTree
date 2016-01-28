#ifndef PARSE_TREE_NODE_H
#define PARSE_TREE_NODE_H

#include "token.h"

struct ParseTreeNode{
    struct ParseTreeNode *m_left_child;
    struct ParseTreeNode *m_right_child;

    Token  *m_token;
};

typedef struct ParseTreeNode ParseTreeNode;

ParseTreeNode* createParseTreeNode(Token *p_token);

#endif
