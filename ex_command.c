#include "main.h"
void ex_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path = path_barbadi(args[0]);
	if (strcmp(full_path,"exit") == 0)
	{
		exit_handle();
	}
	if (full_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execv(full_path, args) == -1)
		{
			perror("excve");
		}
		free(full_path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do
		{

			waitpid(pid, &status, WUNTRACED);
		}while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(full_path);

}
