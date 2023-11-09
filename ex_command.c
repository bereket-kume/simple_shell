#include "main.h"
void ex_command(char **args)
{
	char *command = NULL;
	char *command_kan = NULL;

	if (args)
	{
		command = args[0];
		command_kan = path_barbadi(command);
		if (execve(command_kan, args, NULL) == -1)
		{
			perror("Error.");
		}
	}

}
