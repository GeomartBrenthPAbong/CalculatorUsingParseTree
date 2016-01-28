#ifndef PARSE_TREE_CREATOR_EVALUATOR_H
#define PARSE_TREE_CREATOR_EVALUATOR_H

void prefixExprToParseTree(ParseTreeNode *p_root, Token *expr[], int p_size);
void evaluatorHelper(ParseTreeNode *p_node);
int evaluate(ParseTreeNode *p_root);
void string_writer(ParseTreeNode *p_node);

#endif
