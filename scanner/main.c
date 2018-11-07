#include"SCANNER.h"

FILE *file_ptr;

int main(int argc, char *argv[])
{
	printf("please enter the file directory:\n");
	char file_path[200];
	int path_size=200;
	fgets(file_path,path_size,stdin);
	file_path[strlen(file_path)-1]='\0';

	file_ptr=fopen(file_path,"r");
	while(file_ptr==NULL){
		fprintf(stderr,"No such file or directory\n");
		fprintf(stderr,"please enter a valid  file directory:\n");
		fgets(file_path,path_size,stdin);
		file_path[strlen(file_path)-1]='\0';
		file_ptr=fopen(file_path,"r");
	}

	Tokens t = get_token();

	while(t!=FILEEND){
		printf("%39s\n", "----------------------------------------");
		printf("|  %-10s  |  %20s | \n",table[t].str,table[t].type);
		t = get_token();

	}
	getchar();
	return 0;
}

