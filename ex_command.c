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
<<<<<<< HEAD
		command = args[0];
		if (strchr(command, '/') != NULL)
		{
			command_kan = strdup(command);
		}
		else
		{
			char *path = getenv("PATH");
			char *copy_path = strdup(path);
			char *dir = strtok(copy_path, ":");

			while (dir != NULL)
			{
				command_kan = malloc(strlen(dir) + strlen(command) + 2);
				sprintf(command_kan, "%s/%s", dir, command);
				if (access(command_kan, X_OK) == 0)
				{
					break;
				}
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
				exit(EXIT_SUCCESS);
			}
			free(copy_path);
		}
=======
		pid_t pid = fork();

>>>>>>> fb1f73f1859c7e57f50373f099ec3794277fd8d8
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
<<<<<<< HEAD
		}
		waitpid(pid, &status, 0);
=======
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
>>>>>>> fb1f73f1859c7e57f50373f099ec3794277fd8d8
		free(command_kan);
	}
}
