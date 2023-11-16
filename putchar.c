#include "main.h"
int _putchar(char c)
{
	return (write(1, &c, 1));
}

void prints(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
