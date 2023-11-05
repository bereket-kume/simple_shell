#include "main.h"

 int main(){
	char *lineptr = NULL;
	size_t n = 0;
	int read;
	while((read = getline(&lineptr, &n, stdin)) != -1)
	{
	if (read > 0 && lineptr[read - 1] == '\n')
	{
		lineptr[read-1] = '\0';
	}
		printf("$ ");
	}
	free(lineptr);
	return (0);
}
