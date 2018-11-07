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

	FILE * l=fopen("Lexoutput.txt","w");
	Tokens t = get_token();
	while(t!=FILEEND){
		fprintf(l,"%39s\n","----------------------------------------");
		fprintf(l,"|  %-10s  |  %20s | \n",table[t].str,table[t].type);
		t = get_token();

	}
	fclose(l);
	fclose(file_ptr);
	getchar();
	return 0;
}

