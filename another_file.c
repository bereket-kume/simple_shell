#include "main.h"
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
