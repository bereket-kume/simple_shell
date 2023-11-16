#include "main.h"
void execute_cd(char *directory)
{
	if (directory == NULL)
	{
		directory = getenv("HOME");
	}
	if (chdir(directory) != 0)
	{
		perror("cd error");
	}
	else
	{
		char cwd[PATH_MAX];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("PWD", cwd, 1);
		}
		else
		{
			perror("getcwd error");
		}
	}
}
