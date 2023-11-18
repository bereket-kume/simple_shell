#include "main.h"
/**
 *execute_cmd - is function execute command line
 *@adv: is our parameter
 *@value: is our input
 *@env: is our input
 *@num: is our input parameter
 *@lk: is our input parameter
 *Return: -1 or 0
 */

int execute_cmd(char **value, char **env, int num) 
{
    pid_t pid;
    int status;

    if (value == NULL)
        return (-1);

    if (num == 1) {
        if (access(value[0], X_OK) == 0) 
	{ 
            pid = fork();
            if (pid < 0) {
                perror("./hsh: ");
                exit(1);
            } else if (pid == 0) {
                if (execve(value[0], value, env) == -1) {
                    perror("Execution error");
                    free(value);
                    exit(1);
                }
                exit(0);
            } else {
                free(value);
                waitpid(pid, &status, WUNTRACED);
            }
        } else {
            printf("Command '%s' not found\n", value[0]);
            free(value);
        }
    }

    return 1;
}
