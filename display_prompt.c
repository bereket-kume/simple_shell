#include "main.h"


void prompt(void)
{
	char *charbuffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
		prints("$ ");
	free(charbuffer);
}
