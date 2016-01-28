#include "token.h"
#include <stdlib.h>

Token *createToken(char *p_type, char *p_char){
    Token *token = malloc(sizeof(Token));

    token->m_type = p_type;
    token->m_data_container = malloc(sizeof(union DataContainer));
    token->m_data_container->m_char = p_char;

    return token;
}
