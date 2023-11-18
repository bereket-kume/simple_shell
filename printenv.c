#include "main.h"

void printenv(char **nano)
{
	int s = 0;

	for (; nano[s] ; s++)
		_puts(nano[s]);
}
