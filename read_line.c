#include "main.h"
#define MAX_LINE_LENGTH 1

static char buffer[MAX_LINE_LENGTH];
static int buffer_position = 0;
static int buffer_size = 0;

char *my_getline()
{
    char *line = NULL;
    int line_size = 0;

    while (1)
    {

        if (buffer_position == buffer_size)
	{
            buffer_size = fread(buffer, 1, MAX_LINE_LENGTH, stdin);
            if (buffer_size == 0)
	    {
                if (line_size == 0)
		{
                    return NULL;
                }
		else
		{
                    return line;
                }
            }
            
	    buffer_position = 0;
        }

        char current_char;

	currernt_char = buffer[buffer_position++];
        line = (char *)realloc(line, line_size + 2);

        if (line == NULL)
	{
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        line[line_size] = current_char;
        line[line_size + 1] = '\0';
        line_size++;

        if (current_char == '\n')
	{
            return line;
        }
    }
}
