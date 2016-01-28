#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "token.h"
#include "parse_tree_node.h"
#include "queue.h"
#include "stack.h"
#include "parse_tree.h"
#include "parse_tree_traversal.h"
#include "parse_tree_creator_evaluator.h"

void prefixExprToParseTree(ParseTreeNode *p_root, Token *expr[], int p_size){
    int i = 0;
    ParseTreeNode *current_node = p_root;
    Token *token;

    initializeStack();

    for(;i<p_size;i++){
        token = *(expr + i);

        if(0 == strcmp("op", token->m_type)){
                current_node->m_token = token;
                push(current_node);

                if(NULL == current_node->m_left_child)
                    current_node->m_left_child = createParseTreeNode(NULL);

                current_node = current_node->m_left_child;

        }
        else if(0 == strcmp("num", token->m_type)){
                int *val = malloc(sizeof(int));
                *val = atoi(token->m_data_container->m_char);

                current_node->m_token = token;
                current_node->m_token->m_data_container->m_int = val;

                current_node = pop();

                if(NULL == current_node)
                    break;

                if(NULL == current_node->m_right_child)
                    current_node->m_right_child = createParseTreeNode(NULL);

                current_node = current_node->m_right_child;
        }
    }
}


void evaluatorHelper(ParseTreeNode *p_node){
    if(0 == strcmp("num", p_node->m_token->m_type)){
        push(p_node);
    }
    else if(0 == strcmp("op", p_node->m_token->m_type)){
        char *op;
        int *int_val = malloc(sizeof(int));
        Token *new_token;
        ParseTreeNode *container;

        ParseTreeNode *operand_one_container = pop();
        ParseTreeNode *operand_two_container = pop();

        int operand_two = *(operand_one_container->m_token->m_data_container->m_int);
        int operand_one = *(operand_two_container->m_token->m_data_container->m_int);

         op = p_node->m_token->m_data_container->m_char;

        if(0 == strcmp("*", op))
            *int_val = operand_one * operand_two;
        else if(0 == strcmp("/", op)){
            if(0 == operand_two){
                printf("Error: Division by zero.");
                exit(1);
            }

            *int_val = operand_one / operand_two;
        }
        else if(0 == strcmp("+", op))
            *int_val = operand_one + operand_two;
        else if(0 == strcmp("-", op))
            *int_val = operand_one - operand_two;

        new_token = createToken("num", "0");
        new_token->m_data_container->m_int = int_val;

        container = createParseTreeNode(new_token);

        push(container);
        enqueue(container);
    }
}

int evaluate(ParseTreeNode *p_root){
    ParseTreeNode *result_node;
    int val;

    initializeStack();
    initializeQueue(); /* So that the tree will not be changed */

    postOrderTraversal(p_root, &evaluatorHelper);

    result_node = pop();
    val = *(result_node->m_token->m_data_container->m_int);

    /* Free the resources */
    while(!isQueueEmpty()){
        result_node = dequeue();

        free(result_node->m_token->m_data_container);
        result_node->m_token->m_data_container = NULL;

        free(result_node->m_token);
        result_node->m_token = NULL;

        free(result_node);
        result_node = NULL;
    }

    return val;
}


void string_writer(ParseTreeNode *p_node){
    if(NULL == p_node)
        return;

    if(0 == strcmp("num", p_node->m_token->m_type))
        printf("<%s,%d> ", p_node->m_token->m_type, *(p_node->m_token->m_data_container->m_int));
    else
        printf("<%s,%s> ", p_node->m_token->m_type, p_node->m_token->m_data_container->m_char);
}

