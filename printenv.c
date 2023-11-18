#include "main.h"
/**
 *printenv - is function that env
 *@nano: is our parameter
 *Return: nothing
 */
void printenv(char **nano)
{
	int s = 0;

	for (; nano[s] ; s++)
		_puts(nano[s]);
}
