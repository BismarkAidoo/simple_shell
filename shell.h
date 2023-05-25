#ifndef SHELL_H
#define SHELL_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

#define MAX_ARGS 10
#define MAX_PATH_SIZE 200
#define MAX_INPUT_SIZE 100
#define MAX_TOKEN_SIZE 20
extern char **environ;

int sum(int a, int b);
void printPrompt(const char *prompt);
char *readInput();
int process_exe(char *input);
pid_t getpid(void);
void handle_path(char **args, char *path);
void path_exe(char **args);
char **handle_args(char *input);
#endif
