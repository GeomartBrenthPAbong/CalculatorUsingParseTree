#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "token.h"
#include "parse_tree_node.h"
#include "parse_tree.h"
#include "parse_tree_traversal.h"
#include "parse_tree_creator_evaluator.h"

int parse_tree_test(){
    ParseTreeNode *root = createParseTreeNode(NULL);

    int i=0;
    int num_tokens = 11;

    Token *exp[11];
    Token *token;


    exp[0] = createToken("op", "-");
    exp[1] = createToken("op", "+");
    exp[2] = createToken("op", "*");
    exp[3] = createToken("num", "2");
    exp[4] = createToken("num", "4");
    exp[5] = createToken("op", "+");
    exp[6] = createToken("num", "3");
    exp[7] = createToken("num", "1");
    exp[8] = createToken("op", "+");
    exp[9] = createToken("num", "2");
    exp[10] = createToken("num", "3");

    initializeTree(root);

    prefixExprToParseTree(root, exp, num_tokens);

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

    for(;i<num_tokens;i++){
        token = exp[i];
        free(token->m_data_container);
        token->m_data_container = NULL;

        free(exp[i]);
        exp[i] = NULL;
    }

    return 0;
}
