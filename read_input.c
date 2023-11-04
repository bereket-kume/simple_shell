#include "main.h"

/**
 * read_line_Input - reads the user input commands
 * Return: inputline
*/

char* read_Line_Input() {
    char input[MAX_INPUT_SIZE];
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *newline = strchr(input, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        char *inputLine = strdup(input);
        if (inputLine == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        
        return inputLine;
    } else {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }
}
