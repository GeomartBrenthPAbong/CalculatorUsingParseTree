#include "token.h"
#include "parser.h"

#include <stdlib.h>
#include <ctype.h>

Token **g_tokens;
int g_num_tokens;
char g_buffer[200];
char *g_str_buffer;

void initializeParser(){
    g_num_tokens = 0;
    g_tokens = malloc(sizeof(Token *) * 50);
    g_str_buffer = g_buffer;
}

void parse(char * p_string){
    char current_char;

    while((current_char = *p_string++) != '\0'){
        if(('-' == current_char && isdigit(*p_string)) ||
            isdigit(current_char)){

            g_tokens[g_num_tokens++] = createToken("num", g_str_buffer);
            *g_str_buffer++ = current_char;

            while(isdigit(*p_string)){
                current_char = *p_string++;
                *g_str_buffer++ = current_char;
            }
            *g_str_buffer++ = '\0';

        }
        else if('+' == current_char ||
                '-' == current_char ||
                '/' == current_char ||
                '*' == current_char){
            g_tokens[g_num_tokens++] = createToken("op", g_str_buffer);

            *g_str_buffer++ = current_char;
            *g_str_buffer++ = '\0';
        }
        else
            continue;
    }
}

void deleteTokens(){
    int i = 0;
    Token *current_token;

    for(; i<g_num_tokens; i++){
        current_token = *(g_tokens + i);

        free(current_token->m_data_container);
        current_token->m_data_container = NULL;

        free(current_token);
        current_token = NULL;
    }

    g_num_tokens = 0;

    free(g_str_buffer);
    g_str_buffer = NULL;
}

Token **getTokens(){
    return g_tokens;
}

int getNumTokens(){
    return g_num_tokens;
}
