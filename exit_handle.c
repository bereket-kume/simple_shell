#include "main.h"

/**
 *handle_signal - is function that handle prompt
 *@srs: is our first parameter
 *Return: nothing
 */
void handle_signal(int srs)
{
	(void) srs;
	prints("\n$ ");
	fflush(stdout);
}


int *_error(char *argv, int value, char *args)
{
	char *digit;

	digit = _itoa(value, 10);

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, digit, _strlen(digit));
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	perror(" ");

	return (0);
}


int _stat(char **command_line, char **control)
{
	char *fullstr = NULL, *fullconcat = NULL;
	int lk;
	struct stat sb;

	if (control == NULL)
	{
		free(control);
		free(command_line);
		return (0);
	}
	for (lk = 0; control[lk] != NULL ; lk++)
	{
		fullstr= str_concat(control[lk], "/");
		fullconcat = str_concat(fullstr, command_line[0]);

		if (stat(fullconcat, &sb) == 0 && (sb.st_mode & S_IXUSR))
		{
			command_line[0] = fullconcat;
			free(fullstr);
			free(control[0]);
			free(control);
			return (1);
		}

		free(fullstr);
		free(fullconcat);
	}
	free(control[0]);
	free(control);
	return (0);
}
