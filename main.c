#include "main.h"

 int main(void){
	char *lineptr = NULL;
	size_t n = 0;
	printf("$ ");
	while( getline(&lineptr, &n, stdin) != EOF)
	{ 
		int length = strlen(lineptr);
		lineptr[length - 1] = '\0';
		printf("$ ");
	}
	exit(EXIT_SUCCESS);

}
