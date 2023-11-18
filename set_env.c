#include "main.h"

// ... (previous code)

/**
 * set_env_var - sets or updates an environment variable
 * @variable: the name of the variable
 * @value: the value to set
 * @env: the environment variables array
 * Return: 0 on success, -1 on failure
 */
int set_env_var(const char *variable, const char *value, char ***env) {
    char *new_var;
    int i;

    // Check if the variable already exists
    for (i = 0; (*env)[i] != NULL; i++) {
        if (_strstr((*env)[i], variable) != NULL) {
            // Variable found, update its value
            free((*env)[i]);
            new_var = str_concat(str_concat(variable, "="), value);
            (*env)[i] = _strdup(new_var);
            free(new_var);
            return 0;  // Success
        }
    }

    // Variable not found, add it to the environment
    new_var = str_concat(str_concat(variable, "="), value);
    *env = _realloc(*env, sizeof(char *) * (i + 2));
    if (*env == NULL) {
        perror("Error reallocating memory");
        return -1;  // Failure
    }
    (*env)[i] = _strdup(new_var);
    (*env)[i + 1] = NULL;
    free(new_var);
    return 0;  // Success
}

/**
 * shell_setenv - built-in setenv command
 * @args: command arguments
 * @env: environment variables array
 */
void shell_setenv(char **args, char ***env) {
    if (args[1] == NULL || args[2] == NULL) {
        _error(args[0], 1, "Usage: setenv VARIABLE VALUE");
        return;
    }

    if (set_env_var(args[1], args[2], env) == -1) {
        fprintf(stderr, "Error setting environment variable\n");
    }
}

/**
 * unset_env_var - removes an environment variable
 * @variable: the name of the variable
 * @env: the environment variables array
 * Return: 0 on success, -1 on failure
 */
int unset_env_var(const char *variable, char ***env) {
    int i, j;

    for (i = 0; (*env)[i] != NULL; i++) {
        if (_strstr((*env)[i], variable) != NULL) {
            free((*env)[i]);
            // Remove the variable by shifting the array
            for (j = i; (*env)[j + 1] != NULL; j++) {
                (*env)[j] = (*env)[j + 1];
            }
            // Reallocate memory to remove the last element
            *env = _realloc(*env, sizeof(char *) * i);
            if (*env == NULL) {
                perror("Error reallocating memory");
                return -1;  // Failure
            }
            return 0;  // Success
        }
    }

    fprintf(stderr, "Error: %s not found in environment\n", variable);
    return -1;  // Failure
}

/**
 * shell_unsetenv - built-in unsetenv command
 * @args: command arguments
 * @env: environment variables array
 */
void shell_unsetenv(char **args, char ***env) {
    if (args[1] == NULL) {
        _error(args[0], 1, "Usage: unsetenv VARIABLE");
        return;
    }

    if (unset_env_var(args[1], env) == -1) {
        fprintf(stderr, "Error unsetting environment variable\n");
    }
}
