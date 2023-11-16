#include "main.h"
/**
 *main - the beging of our function
 *@ac: is our firat parameter
 *@av: is another parameter
 *@env: is third parameter
 *Return: nothing
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *sarara;
	char **args, **path;
	int lk = 0, key_value = 0;
	(void) av;
	signal(SIGINT, handle_signal);

	for (;;)
	{
		prompt();
		sarara = read_input();
		args = split_str(sarara, env);
		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			lk += 1;
			path = search(env);
			key_value = _stat(args, path);
			execute_cmd(av, args, env, key_value, lk);
		}
		else
		{
			free(args);
		}
		free(sarara);
	}
	return (0);
}
