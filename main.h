#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/wait.h>
void getline_fun();
void token_fun();
void ex_command(char **args);
#endif
