#include"SCANNER.h"
char code_line[buffer_size] ;
int current_position =0;
int buffer_length = 0 ;

typedef enum State{
    START,INCOMMENT,INASSIGN,INNUM,INID,DONE
} States;


 TOKES keywords[]=
{
#define TOKENS_KEYWORD(x, y,z) {y,x,z},
  LANG_KEYWORDS
#undef TOKENS_KEYWORD
};

Tokens check_keywords(char* str1){
	for(int i =0;i<keywords_num;i++ ){
		if (!strcmp(str1, keywords[i].str))
		return keywords[i].val;
	}
	return IDNETIFIER;
}
Tokens check_sympols(char c){
	switch(c){
			case '+' : return PLUS;
			case '-' : return MINUS;
			case '*' : return MULT;
			case '/' : return DIV;
			case '=' : return EQUAL;
			case '<' : return STHAN;
			case '>' : return LTHAN;
			case '(' : return LPARA;
			case ')' : return RPARA;
			case ';' : return SCOLON;

			}
	return ERROR;
}

TOKES table[]={
#define TOKENS(name,_a,_b) {_a,name,_b},
#define TOKENS_KEYWORD(x, y,z) TOKENS(x, y,z)
#define TOKENS_OTHER(x,y,z)    TOKENS(x,y,z)
	LANG_TOKENS
#undef TOKENS_OTHER
#undef TOKENS_KEYWORD
#undef TOKENS
};

char look_up(){

	if(!(current_position<buffer_length)){
		if(fgets(code_line, buffer_size-1,file_ptr )){
			buffer_length = strlen(code_line);
			current_position = 0;
			return code_line[current_position++];
		}

		else{
			return EOF ;
		}

	}
	else{
		return code_line[current_position++];
	}
}

void put_back(){
	current_position--;
}

Tokens get_token(){
char string_token[20];
Tokens accepted_token;
int index =0 ;
States current_state = START;
while((current_state!=DONE)){
	char ch = look_up();
	int flag = 1;
	switch(current_state) {
	case START :
		if(isdigit(ch)|| ch=='.')
			{current_state = INNUM ;}
		else if(isalpha(ch))
			{current_state = INID  ;}
		else if(ch == ':')
			{current_state =INASSIGN ;}
		else if((ch==' ') || (ch=='\n') || (ch=='\t'))
			{current_state = START;flag=0;}
		else if(ch=='{')
			{current_state=INCOMMENT;flag=0;}
		else if(ch==EOF){current_state=DONE;accepted_token=FILEEND;}
		else
		{current_state=DONE;
		accepted_token=check_sympols(ch);


		}
	break;
////////////////////////////////////////////////////////////////////////////////
	case INASSIGN:
		if(ch == '='){
			current_state= DONE;accepted_token = ASSIGN;flag=0;
			break;
		}
		else{
			accepted_token=ERROR;flag=0;
			break;
		}
///////////////////////////////////////////////////////////////////////////////
	case INCOMMENT:
		current_state= INCOMMENT;
		if(ch=='}'){
			current_state=START;}
		flag=0;
		break;
///////////////////////////////////////////////////////////////////////////////
	case INNUM :
		if(!isdigit(ch)){
			if(ch=='.'){current_state=INNUM;}
			else{
				put_back();current_state=DONE;accepted_token=NUMBER;flag=0;
			}

		}
		break;
////////////////////////////////////////////////////////////////////////////////
	case INID:
		if(!isalpha(ch)){
			current_state=DONE;
			put_back();
			accepted_token=IDNETIFIER ;
			flag = 0;
		}
		break;
///////////////////////////////////////////////////////////////////////////////
	case DONE :
		break;
	default:
		accepted_token=ERROR;
		break;
	}
	if(flag){
		string_token[index++]=ch;
	}
	if(current_state ==DONE){
		string_token[index]='\0';
		if(accepted_token == IDNETIFIER){
			accepted_token=check_keywords(string_token);
			if(strcmp(table[accepted_token].type,"keyword")!=0){
				strcpy(table[accepted_token].str,string_token);
						}
		}
		else if (accepted_token == NUMBER ){
			strcpy(table[NUMBER].str,string_token);
		}

	}
}

return accepted_token;
}














































