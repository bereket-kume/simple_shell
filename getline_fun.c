#include "main.h"
#define DELIM " \t\r\n\a"

/**
 * getline_fun - function that parses input from the user
 * Return: nothing
 */
void getline_fun(void)
{
    char *lineptr = NULL, *token, *args[64];
    size_t n = 0;
    int i;
<<<<<<< HEAD
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
    do
    {
        ssize_t read_size;
	display_prompt();
       	read_size = getline(&lineptr, &n, stdin);
=======

    display_prompt();

    while (1)
    {
        ssize_t read_size = getline(&lineptr, &n, stdin);

>>>>>>> 54d70d9d7ce31e6af4b51855d5012f91a870df24
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
        }

        display_prompt();
    }

    if (lineptr != NULL)
    {
        free(lineptr);
    }
}
