#include "main.h"
 int main()
{
	char *lineptr = NULL;
	size_t n = 0;
	while(getline(&lineptr, &n, stdin) != EOF)
	{
		int length = strlen(lineptr);
		lineptr[length-1] = '\0';
		printf("$ ");
	}
	return (0);
}
