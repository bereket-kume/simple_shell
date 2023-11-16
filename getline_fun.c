#include "main.h"
/**
 *read_input - is function that take input form user
 *Return: nothing
 */
char *read_input(void)
{
	char *sarara = NULL;
	ssize_t valueread;
	size_t demo;
	int i;

	demo = 0;
	valueread = getline(&sarara, &demo, stdin);
	if (!sarara)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (valueread == 1)
	{
		free(sarara);
		return (NULL);
	}
	else if (valueread == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(sarara);
		exit(0);
	}
	else
	{
		for (i = 0; sarara[i] == ' ' && sarara[i + 1] == ' '; i++)
			;
		if (!sarara[i] && sarara[i + 1] == '\n')
		{
			free(sarara);
			return (0);
		}
	}

	return (sarara);
}
