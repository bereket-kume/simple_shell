#include "main.h"
void ex_command(char **args)
{
	char *command = NULL;
	char *command_kan = NULL;
	int status;

	if (args)
	{
		pid_t pid = fork();
		command = args[0];
		command_kan = path_barbadi(command);
		if (pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
		if (execve(command_kan, args, NULL) == -1)
		{
			perror("Error.");
			exit(EXIT_FAILURE);
		}
		}
		else
		{
			waitpid(pid, &status, 0);
		}

	}
	

}
