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
	pid_t pid = fork();

	if (args && args[0])
	{
				free(command_kan);
				dir = strtok(NULL, ":");
			}
			if (strcmp("exit", command) == 0)
			{
				exit(EXIT_FAILURE);
			}
			if (dir == NULL)
			{
				fprintf(stderr, "Command not found in PATH: %s\n", command);
				free(copy_path);
				exit(EXIT_FAILURE);
			}
			free(copy_path);
		}

		if (strcmp(command, "exit") == 0)
		{
			exit(EXIT_FAILURE);
		}

		if (pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(command_kan, args, NULL) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
			free(command_kan);
		}
	}
}
