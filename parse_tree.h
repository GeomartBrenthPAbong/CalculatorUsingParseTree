#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <stdbool.h>

void initializeTree(ParseTreeNode *p_root_node);

void setLeftChild(ParseTreeNode *p_left_node);
void setRightChild(ParseTreeNode *p_right_node);

ParseTreeNode* getLeftChild();
ParseTreeNode* getRightChild();
ParseTreeNode* getCurrentNode();

void gotoLeftChild();
void gotoRightChild();
void gotoRootNode();

bool hasLeftChild();
bool hasRightChild();
bool isValidNode();

void store(Token *p_token);
Token* getData();

void deleteTreeFunc(ParseTreeNode* p_runner_node);
void deleteTree();

#endif
