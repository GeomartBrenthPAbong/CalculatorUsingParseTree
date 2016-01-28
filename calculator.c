
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "parse_tree_node.h"
#include "parse_tree.h"
#include "parse_tree_traversal.h"
#include "parse_tree_creator_evaluator.h"
#include "parser.h"

typedef char *string;

int main (int x, char *argv[]){
    string inputS = argv[1];
    ParseTreeNode *root;

	if(x!=2){
		printf("Please input any infix expression in between quotes.\n");
		exit(1);
	}

    printf("INPUT: %s\n", inputS);

    root = createParseTreeNode(NULL);
    initializeTree(root);

    initializeParser();
    parse(inputS);

    prefixExprToParseTree(root, getTokens(), getNumTokens());

    printf("\n\nResult after evaluation: %d\n", evaluate(root));

    printf("\n\nPreorder Traversal:\n");
    preOrderTraversal(root, &string_writer);

    printf("\n\nInorder Traversal:\n");
    inOrderTraversal(root, &string_writer);

    printf("\n\nPostorder Traversal:\n");
    postOrderTraversal(root, &string_writer);

    printf("\n\nBFS:\n");
    BFS(root, &string_writer);

    printf("\n\nDFS:\n");
    DFS(root, &string_writer);

    /* Free the resources */
    deleteTree();
    root = NULL;

    deleteTokens();

	return 0;
}
