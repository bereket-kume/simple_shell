#include "main.h"

char *my_strtok(char *str, const char *delimiters) {
    static char *lastToken = NULL;
    char *tokenStart;

    if (str != NULL) {
        lastToken = str;
    } else {

        if (lastToken == NULL) {
            return NULL;
        }
    }

    tokenStart = lastToken + strspn(lastToken, delimiters);

    if (*tokenStart == '\0') {
        lastToken = NULL;
        return NULL;
    }

    lastToken = tokenStart + strcspn(tokenStart, delimiters);

    if (*lastToken != '\0') {
        *lastToken = '\0';
        lastToken++;
    } else {
        lastToken = NULL;
    }

    return tokenStart;
}
