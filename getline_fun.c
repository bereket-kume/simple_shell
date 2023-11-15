#include "main.h"
#define DELIM " \t\r\n\a"

<<<<<<< HEAD
	_putchar('$');
	_putchar(' ');
	while (1)
	{
		ssize_t read = my_getline();
=======
/**
 * getline_fun - function that parses input from the user
 * Return: nothing
 */
void getline_fun(void)
{
    char *lineptr = NULL, *token, *args[64];
    size_t n = 0;
    int i;
>>>>>>> 51f1b5d14b59137087552849aa076499a7290fa2

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
        }

        display_prompt();
    }

    if (lineptr != NULL)
    {
        free(lineptr);
    }
}
