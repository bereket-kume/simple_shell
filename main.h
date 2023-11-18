#ifndef MAIN_H
#define MAIN_H

#include "val.h"
extern char **environ;
void _puts(char *str);
int execute_cmd(char **av, char **args, char **environ, int ymh, int kotari);
char **search(char **environ);
char **_which(char *fpath);
void handle_signal(int signal);
int _stat(char **cmd, char **menged);
int *_error(char *argv, int count, char *args);
void *_calloc(unsigned int nmemb, unsigned int size);
int _putchar(char c);
void prints(char *str);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_itoa(int num, int base);
int _atoi(char *a);
char **split_str(char *line, char **env);
void prompt(void);
char *read_input();
void printenv(char **environ);



#endif
