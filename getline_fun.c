#include "main.h"
#define DELIM " \t\r\n\a"
 void getline_fun(){
	char *lineptr = NULL;
	size_t n = 0;
	printf("$ ");
	while( getline(&lineptr, &n, stdin) != EOF)
	{ 
		int length = strlen(lineptr);
		char *token;
		lineptr[length - 1] = '\0';
		token = strtok(lineptr, DELIM);
		printf("$$%s ", token);
	}
}
