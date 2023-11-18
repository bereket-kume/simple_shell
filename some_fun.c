#include "main.h"
/**
 *_calloc is function that parse our input
 *@num: is our first input
 *@han: is our second input
 *Return: nothing
 */
void *_calloc(unsigned int num, unsigned int han)
{
	char *D;
	unsigned int j;

	if (num == 0 || han == 0)
		return (NULL);

	D = malloc(num * han);
	if (D == NULL)
		return (NULL);

	for (j = 0; j < num * han; j++)
		D[j] = 0;

	return (D);

}
/**
 *_puts - is function that find command
 *@jch: is our first input
 *Return: nothing
 */
void _puts(char *jch)
{
	int j;

	for (j = 0 ; jch[j] != '\0' ; j++)
	{
		_putchar(jch[j]);
	}
	_putchar('\n');
}
/**
 *search - is function that search for command
 *@nano: is parameter
 *Return: nothing
 */
char **search(char **nano)
{
	int iddo = 0;
	char **sarara;

	for (; nano[iddo] != NULL ; iddo++)
	{
		if (nano[iddo][0] == 'P' && nano[iddo][2] == 'T')
		{
			sarara = _which(nano[iddo]);
		}
	}
	return (sarara);
}
/**
 *_itoa is function that do some work
 *@lak: first parameter
 *@hun: is first parameter
 *Reurn: nothing
 */
char *_itoa(int lak, int hun)
{
	static char *kal = "0123456789abcdef";
	static char buf[50];
	char mal = 0;
	char *kr;
	unsigned long D = (unsigned long)lak;

	if (lak < 0)
	{
		D = (unsigned long)(-lak);
		mal = '-';
	}

	kr = &buf[49];
	*kr = '\0';
	do {
		*--kr = kal[D % hun];
		D /= hun;
	} while (D != 0);

	if (mal)
		*--kr = mal;

	return (kr);
}
/**
 *str_concat - isfunction that do something
 *@D!: is our first parmater
 @D@: is our second argument
 *Return: nothing
 */
char *str_concat(char *D1, char *D2)
{
	char *ch;
	unsigned int k, l, han;

	if (D1 == NULL)
		D1 = "";

	if (D2 == NULL)
		D2 = "";

	han = (_strlen(D1) + _strlen(D2) + 1);

	ch = (char *) malloc(han * sizeof(char));

	if (ch == 0)
	{
		return (NULL);
	}

	for (k = 0; *(D1 + k) != '\0'; k++)
		*(ch + k) = *(D1 + k);

	for (l = 0; *(D2 + l) != '\0'; l++)
	{
		*(ch + k) = *(D2 + l);
		k++;

	}
	ch[k] = '\0';
	return (ch);

}
void printenv(char **nano)
{
	int s = 0;

	for (; nano[s] ; s++)
		_puts(nano[s]);
}
