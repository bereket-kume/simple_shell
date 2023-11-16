#include "main.h"

int execute_cmd(char **adv, char **value, char **env, int num, int lk)
{
	pid_t pid;
	int status;

	if (value == NULL)
		return (-1);
	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(value[0], value, env) == -1)
		{
			_error(adv[0], lk, value[0]);
			free(value);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (num == 1)
			free(value[0]);

		free(value);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
