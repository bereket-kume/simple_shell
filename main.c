#include "main.h"
/**
 *main - the beging of our function
 *@ac: is our firat parameter
 *@av: is another parameter
 *@env: is third parameter
 *Return: nothing
 */

int main(int ac __attribute__((unused)), char **av, char **env) {
    char *sarara;
    char **args, **path;
    int lk = 0, key_value = 0;
    signal(SIGINT, handle_signal);

    for (;;) {
        printf("$ ");
        fflush(stdout);
        size_t bufsize = 0;
        getline(&sarara, &bufsize, stdin);

        char *token;
        token = strtok(sarara, " \t\r\n\a");
        int i = 0;
        args = malloc(64 * sizeof(char *));
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \t\r\n\a");
        }
        args[i] = NULL;

        if (args[0] != NULL) {
            lk += 1;
            path = search(env);
            key_value = _stat(args, path);

            if (strcmp(args[0], "cd") == 0) {
                handle_cd(args); 
            } else {
                pid_t pid = fork();
                if (pid < 0) {
                    perror("Fork error");
                    exit(EXIT_FAILURE);
                } else if (pid == 0) {
                    if (execvp(args[0], args) == -1) {
                        perror("Execution error");
                        exit(EXIT_FAILURE);
                    }
                    exit(EXIT_SUCCESS);
                } else {
                    wait(NULL);
                }
            }
        }

        free(args);
        free(sarara);
    }

    return 0;
}
