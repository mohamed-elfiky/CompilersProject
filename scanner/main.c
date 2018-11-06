#include"SCANNER.h"

FILE *file_ptr;

int main(int argc, char *argv[])
{
	printf("please enter the file directory:\n");
	char * file_path;

	int path_size =200;
	path_size=getline(&file_path,&path_size,stdin);
	file_path[path_size-1]='\0';
	file_ptr=fopen(file_path,"r");
	Tokens t = get_token();
	while(t!=FILEEND){
		printf("%39s\n", "----------------------------------------");
		printf("|  %-10s  |  %20s | \n",table[t].str,table[t].type);
		t = get_token();
	}
	return 0;
}

