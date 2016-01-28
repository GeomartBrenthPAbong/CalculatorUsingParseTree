#ifndef TOKEN_H
#define TOKEN_H

union DataContainer{
    char *m_char;
    int *m_int;
};

struct Token{
    char *m_type;

    union DataContainer *m_data_container;
};

typedef struct Token Token;

Token *createToken(char *p_type, char *p_char);

#endif
