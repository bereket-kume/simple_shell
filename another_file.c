#include "main.h"
/**
 *_strlen - is function perform task
 *@jch: is our first parameter
 *Return: nothing
 */
int _strlen(const char *jch)
{
	int lak;

	lak = 0;
	while (jch[lak] != '\0')
	{
		lak++;
	}
	return ((lak + 1));
}
/**
 *_strcpy - is function that perrfform copy of text
 *@ch: is first argument
 *@ka: is our srgument
 *Return: nothing
 */
char *_strcpy(char *ch, char *ka)
{
	int D;

	for (D = 0; ka[D] != '\0'; D++)
	{
		ch[D] = ka[D];
	}
	ch[D] = '\0';

	return (ch);
}
/**
 *_memcpy - is function copy function
 *@ch: is argument
 *@ka: is our parameter
 *@D: is our third parameter
 *Return: nothing
 */
char *_memcpy(char *ch, char *ka, unsigned int D)
{
	int j;

	for (j = 0; D > 0; j++)
	{
		ch[j] = ka[j];
		D--;
	}

	return (ch);
}
/**
 *_strdup - is function that dupilcate input
 *@jch: is our first parameter
 *Return: nothing
 */

char *_strdup(char *jch)
{
	char *man;
	unsigned int j, lak;

	j = 0;
	lak = 0;
	if (jch == NULL)
		return (NULL);
	while (jch[j] != '\0')
	{
		j++;
		lak++;
	}
	lak++;
	man = malloc(sizeof(char) * lak);
	if (man == NULL)
		return (NULL);
	for (j = 0; j < sizeof(char) * lak; j++)
		man[j] = jch[j];

	return (man);
}
/**
 *_strcmp - is function that compare string
 *@jch1: is our first parameter
 *@jch2: is our argument
 *Return: nothing
 */

int _strcmp(char *jch1, char *jch2)
{
	int n;

	n = 0;
	while (jch1[n] != '\0' && jch2[n] != '\0')
	{
		if (jch1[n] != jch2[n])
			return (jch1[n] - jch2[n]);

		n++;
	}

	return (0);
}
