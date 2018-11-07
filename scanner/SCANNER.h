/*
 * SCANNER.h
 *
 *  Created on: Oct 29, 2018
 *      Author: mohamed
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include <errno.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
#define buffer_size 256
#define keywords_num 8

#define LANG_KEYWORDS   									\
TOKENS_KEYWORD(IF,"if","keyword")							\
TOKENS_KEYWORD(THEN,"then","keyword")						\
TOKENS_KEYWORD(ELSE,"else","keyword")						\
TOKENS_KEYWORD(END,"end","keyword")							\
TOKENS_KEYWORD(REPEAT,"repeat","keyword")					\
TOKENS_KEYWORD(UNTIL,"until","keyword")						\
TOKENS_KEYWORD(READ,"read","keyword")						\
TOKENS_KEYWORD(WRITE,"write","keyword")

#define LANG_SYMPOLS                    				\
TOKENS(PLUS,"+","special symbol")						\
TOKENS(MINUS,"-","special symbol")						\
TOKENS(MULT,"*","special symbol")						\
TOKENS(DIV,"/","special symbol")						\
TOKENS(EQUAL,"=","special symbol")						\
TOKENS(STHAN,"<","special symbol")						\
TOKENS(LTHAN,">","special symbol")						\
TOKENS(LPARA,"(","special symbol")						\
TOKENS(RPARA,")","special symbol")						\
TOKENS(SCOLON,";","special symbol")						\
TOKENS(ASSIGN,":=","special symbol")

#define LANG_OTHER 									\
TOKENS_OTHER(NUMBER," ","number ")					\
TOKENS_OTHER(IDNETIFIER," ","identifier ")			\
TOKENS_OTHER(ERROR," ","error ")						\
TOKENS_OTHER(FILEEND," ","FILEEND ")

#define LANG_TOKENS \
LANG_OTHER 			\
LANG_KEYWORDS		\
LANG_SYMPOLS

typedef	enum
{
	#define TOKENS(name,_a,_b) name,
	#define TOKENS_KEYWORD(x, y,_) TOKENS(x, y,_)
	#define TOKENS_OTHER(x,y,_)    TOKENS(x,y,_)
		LANG_TOKENS
	#undef TOKENS_OTHER
	#undef TOKENS_KEYWORD
	#undef TOKENS
}Tokens;
typedef struct{char str[20];Tokens val ;char type[20];}TOKES;
extern TOKES keywords[] ;
extern TOKES table[]   ;
extern FILE *file_ptr ;
Tokens check_sympols(char c);
Tokens check_keywords(char* str1);
char look_up();
Tokens get_token();

#endif /* SCANNER_H_ */
