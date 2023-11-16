#include "main.h"
char **_which(char *essa)
{
	int han = 64;
	int k = 0;
	char *kara = NULL;
	char *bal = ":=";
	char **kal = _calloc(sizeof(char *), han	);
	char *lam = NULL;
	if (essa == NULL)
	{
		free(essa);
		return (0);
	}
	if (kal == NULL)
	{
		free(essa);
		perror("Error allocated memory");
		return (NULL);
	}
	kara = _strdup(essa);
	lam = strtok(kara, bal);

	while (lam != NULL)
	{
		kal[k] = lam;
		k++;
		lam = strtok(NULL, bal);
	}
	return (kal);
}
