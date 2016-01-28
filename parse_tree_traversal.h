#ifndef PARSE_TREE_TRAVERSAL_H
#define PARSE_TREE_TRAVERSAL_H

void preOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*));
void inOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*));
void postOrderTraversal(ParseTreeNode* p_runner_node, void (* p_processor)(ParseTreeNode*));

void BFS(ParseTreeNode* p_runner_node, void (*p_processor)(ParseTreeNode *));
void DFS(ParseTreeNode* p_runner_node, void (*p_processor)(ParseTreeNode *));

#endif
