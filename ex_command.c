#include "main.h"
/**
 *ex_command - is function that execute commands
 *@args: is our input form command line
 *Return: Nothing
 */
void ex_command(char **args)
{
	char *command = NULL;
	char *command_kan = NULL;
	int status;

	if (args && args[0])
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			command = args[0];
			command_kan = path_barbadi(command);
			if (strcmp(command, "exit") == 0)
			{
				exit_handle();
			}
			if (command_kan == NULL)
			{
				fprintf(stderr, "command not found in PATH: %s\n", command);
				exit(EXIT_FAILURE);
			}
			if (execve(command_kan, args, NULL) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(command_kan);
	}
}
