#include "main.h"

/**
 *_strcspn - return the index at which the match occured
 *@str: the sstring passed to the function
 *@reject: arrgument passed to the fun to be rejected
 *Return: the counted number
 */

size_t _strcspn(const char *jch, const char *bal)
{
	size_t lakk = 0;

	while (*jch)
	{
		const char *Q = bal;
		while (*Q)
		{
			if (*jch == *Q)
			{
				return lakk;
			}
			Q++;
		}
		jch++;
		lakk++;
		
	}
	return lakk;
}

/**
 *_strspn - accept from the string
 *@str: the string passed to the function
 *@accepted string passed to the function
 *Return: the counted value
 */

size_t _strspn(const char *jch, const char *gal)
{
	size_t lakk = 0;
	while (*jch)
	{
		const char *E = gal;
		int bar = 0;
		while (*E)
		{
			if (*jch == *E)
			{
				bar = 1;
				break;
			}
			E++;
		}
		if (!bar)
		{
			return lakk;
		}
		jch++;
		lakk++;
	}

	return lakk;
}

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
        if(getcwd(cwd, sizeof(cwd)) != NULL)
        {
            setenv("PWD", cwd, 1);
        }
        else
        {
            perror("getcwd error");
        }
    }
}
