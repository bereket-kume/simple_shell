#include "main.h"

/**
 *prompt - is function display prompt to user
 *Return: nothing
 */
void prompt(void)
{
	char *charbuffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(charbuffer);
}
