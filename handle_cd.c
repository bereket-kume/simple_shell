#include "main.h"
void handle_cd(char **args) {
    char *new_directory;

    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        new_directory = getenv("HOME");
    } else if (strcmp(args[1], "-") == 0) {
        new_directory = getenv("OLDPWD");
    } else {
        new_directory = args[1];
    }

    int success = chdir(new_directory);
    if (success == -1) {
        perror("cd"); 
    } else {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            setenv("PWD", cwd, 1);
            setenv("OLDPWD", new_directory, 1);
        } else {
            perror("getcwd");
        }
    }
}
