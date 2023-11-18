#include "main.h"



char *_memset(char *sun, char bun, unsigned int nun)
{
	unsigned int i;

	for (i = 0; i < nun; i++)
		sun[i] = bun;
	return (sun);
}

void ffree(char **oo)
{
	char **uu = oo;

	if (!oo)
		return;
	while (*oo)
		free(*oo++);
	free(uu);
}

void *_realloc(void *dd, unsigned int old_size, unsigned int new_size)
{
	char *ss;

	if (!dd)
		return (malloc(new_size));
	if (!new_size)
		return (free(dd), NULL);
	if (new_size == old_size)
		return (dd);

	ss = malloc(new_size);
	if (!ss)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		ss[old_size] = ((char *)dd)[old_size];
	free(dd);
	return (ss);
}


int bfree(void **oooptr)
{
	if (oooptr && *oooptr)
	{
		free(*oooptr);
		*oooptr = NULL;
		return (1);
	}
	return (0);
}
