#include "main.h"
#define DELIM " \t\r\n\a"
 void getline_fun(){
	char *lineptr = NULL;
	size_t n = 0;
	char *token;
	char *args[64];
	int i;

	_putchar('$');
	_putchar(' ');
	while (1)
	{
		ssize_t read = getline(&lineptr, &n, stdin);

		if (read == -1)
		{
			if (lineptr == NULL)
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
			token = strtok(lineptr, DELIM);
			i = 0;
			while (token != NULL)
			{
				args[i] = token;
				i++;
				token = strtok(NULL, DELIM);
			}
			args[i] = NULL;
			ex_command(args);
		}
		_putchar('$');
	
	}
	if (lineptr != NULL)
	{
		free(lineptr);
	}
}
