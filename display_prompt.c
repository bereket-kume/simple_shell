#include "main.h"

void display()
{
	char *lineptr = NULL;
	size_t n = 0;
	printf("$ ");
	while(getline(&lineptr, &n, stdin) != EOF)
	{
		int length = strlen(lineptr);
		lineptr[length - 1] = '\n';
		printf("%s\n",lineptr);
		printf("$ ");
	}
	exit(EXIT_SUCCESS);
}
