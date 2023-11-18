#include "main.h"
/**
 *handle_exit - is function handle_exit
 *@guyya: is our first parameter
 *@sarara: is second parmeter
 *Return: nothing
 */
void handle_exit(char **guyya, char *sarara);

/**
 *split_str - is function that spilt input string
 *@sarara: input from command
 *@env: input to be checked
 *Return: nothing
 */
char **split_str(char *sarara, char **env)
{
	char *tokenized_j, *sepval = " \t\r\n\a";
	char **guyya;
	int max_val = 64, lk = 0;

	if (sarara == NULL)
	{
		return (0);
	}
	guyya = _calloc(sizeof(char *), max_val);
	if (guyya == NULL)
	{
		prints("error");
		exit(EXIT_FAILURE);
	}
	tokenized_j = my_strtok(sarara, sepval);
	while (tokenized_j != NULL)
	{
		guyya[lk] = tokenized_j;
		lk++;
		tokenized_j = my_strtok(NULL, sepval);
	}
	if (guyya[0] == NULL)
		guyya[lk] = "\n";
	if (_strcmp(guyya[0], "exit") == 0)
	{
		if (guyya[1] != NULL)
			handle_exit(guyya, sarara);
		else
			handle_exit(guyya, sarara);
	}
	if ((_strcmp(guyya[0], "env") == 0) && guyya[1] == NULL)
		printenv(env);
	return (guyya);

}
/**
 *handle_exit - is function exit command
 *@guyya: is our parameter
 *@sarara: is our parameter
 *Return: nothing
 */
void handle_exit(char **guyya, char *sarara)
{
	int status = 0;

	if (guyya[1] != NULL)
	{
		status = _atoi(guyya[1]);
		if (status == 0 && _strcmp(guyya[1], "0") != 0)
			status = 2;
	}
	free(sarara);
	free(guyya);
	exit(status);
}
/**
 *_atoi - is function works on input form command line
 *@a: is parameter of our function
 *Return: nothing
 */
int _atoi(char *a)
{
	int result = 0;
	int key = 1;
	int i = 0;

	while (a[i] == ' ')
	{
		i++;
	}
	if (a[i] == '-' || a[i] == '+')
	{
		key = (a[i] == '-') ? -1 : 1;
		i++;
	}
	while (a[i] > '\0' && a[i] <= '9')
	{
		result = result * 10 + (a[i] - '0');
		i++;
	}

	return (result * key);
}
