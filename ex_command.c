#include "main.h"



int execute_cmd(char **av, char **args, char **env, int ymh, int kotari)
{
	pid_t pid;
	int status;

<<<<<<< HEAD
				while(dir != NULL)
				{
					command_kan = malloc(strlen(dir) + strlen(command) + 2);
					sprintf(command_kan, "%s/%s", dir, command);
					if(access(command_kan, X_OK) == 0)
					{
						break;
					}
					free(command_kan);
					dir = strtok(NULL, ":");
				}
				if (dir == NULL)
				{
					if (strcmp(command, "exit") == 0)
					{
						exit(EXIT_SUCCESS);
					}
					fprintf(stderr, "command not found in PATH: %s\n", command);
					free(path_copy);
					exit(EXIT_SUCCESS);
				}
				free(path_copy);
			}
			if  (execve(command_kan, args, NULL) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
		else
=======
	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
>>>>>>> 5388fc2975ef002ae46f229681dccfd0805b7dcf
		{
			_error(av[0], kotari, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (ymh == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
