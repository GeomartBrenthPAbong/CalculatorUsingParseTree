
#ifndef PARSER_H
#define PARSER_H

void initializeParser();
void parse(char * p_string);
void deleteTokens();

Token** getTokens();
int getNumTokens();

#endif
