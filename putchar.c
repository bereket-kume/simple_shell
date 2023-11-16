#include "main.h"
/**
 *_putchar - is function that is used print char
 *@c: is our input char
 *Return: _putchar
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *prints - is function that is used print string
 *@str: is first input
 *Return: nothing
 */
void prints(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
