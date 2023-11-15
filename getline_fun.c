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
}#include "main.h"
#define DELIM " \t\r\n\a"
/**
 * getline_fun - function that parses input from the user
 * Return: nothing
 */
void getline_fun(int argc, char *argv[])
{
    char *lineptr = NULL, *token, *args[64];
    size_t n = 0;
    int i;
    if (argc > 1)
    {
	    for (i = 1; i < argc; i++)
	    {
		    args[i - 1] = argv[i];
	    }
	    args[argc-1] = NULL;
	    ex_command(args);
	    return;
    }
    display_prompt();

    while (1)
    {
        ssize_t read_size = getline(&lineptr, &n, stdin);
        if (read_size == -1)
        {
            if (lineptr != NULL)
            {
                free(lineptr);
            }
            break; 
        }
        if (read_size > 0)
        {
            if (lineptr[read_size - 1] == '\n')
            {
                lineptr[read_size - 1] = '\0';
            }
            token = my_strtok(lineptr, DELIM);
            i = 0;
            while (token != NULL)
            {
                args[i] = token;
                i++;
                token = my_strtok(NULL, DELIM);
            }
            args[i] = NULL;
	    ex_command(args);
        }
        display_prompt();
    }
    if (lineptr != NULL)
    {
        free(lineptr);
    }
}
