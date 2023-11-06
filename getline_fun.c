#include "main.h"
#define DELIM " \t\r\n\a"
 void getline_fun(){
	char *lineptr = NULL;
	size_t n = 0;
	printf("$ ");
	while (1)
	{
		ssize_t read = getline(&lineptr, &n, stdin);
		if (read = -1)
		{
			if (lineptr = NULL)
			{
				free(lineptr);
			}
			break;
		}
		if (read > 0)
		{
			if (lineptr[read - 1] == '\n')
			{
				lineptr[read - 1] = '\0';
			}
			char *token = strtok(lineptr, DELIM);
			char *args[64];
			int i = 0;
			while (token != NULL)
			{
				args[i] = token;
				i++;
				token = strtok(NULL, DELIM);
			}
			args[i] = NULL;
			ex_command(args);
		}
	}
	if (lineptr != NULL)
	{
		free(lineptr);
	}


}
