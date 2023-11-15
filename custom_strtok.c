#include "main.h"

/**
 * my_strtok - tokenize the entered string
 * @strn: the string entered
 * @del: the character based on which the string is divided
 * Return: token start if the string isn't null else NULL
*/

char *my_strtok(char *strn, const char *del)
{
    static char *l_tok;
    char *tok_s;

    if (strn != NULL)
    {
        l_tok = strn;
    }
    else
    {
        if (l_tok == NULL)
        {
            return (NULL);
        }
    }
    tok_s = l_tok + _strspn(l_tok, del);
    if (*tok_s == '\0')
    {
        l_tok = NULL;
        return (NULL);
    }
    l_tok = tok_s + _strcspn(tok_s, del);
    if (*l_tok != '\0')
    {
        *l_tok = '\0';
        l_tok = NULL;  
    }
    return (tok_s);
}
