#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * struct shell_structure - defines a data structure for the shell commands
 * @command: pointer to an instruction representing a shell command
 * @args: pointer to pointer or an arrary of strings representing
 * arguments for the command.
 * @next: pointer to the next node of shell_structure.
 * Description: shell_structure is a command and arguments data structure
 * which stores a command and all its arguments if any.
 */
typedef struct shell_structure
{
	char *command;
	char **args;
	struct shell_structure *next;
} shell_cmd;

/**
 * struct shell_built_in_s - structure for built_in commands
 * @cmdname: Command name to be called.
 * @function: function performing the command task
 * Description: The structure contains the name of a function
 * to be called and a function pointer to the function to be called.
 */
typedef struct shell_built_in_s
{
	char *cmdname;
	void (*function)(char *arg);
} built_in;

shell_cmd *create_command_buf(shell_cmd **head, char *line);
void line_break_down(char **cmd, char **args[], char *line);
char *search_path_and_create(char *cmdname);
char *get_environ_value(char *env_variable);
int leading_space(char **buffer, char *line, int size);
char *_strtok(char *str, char *delim);
void handle_sigint(int sig __attribute__((unused)));
void concat_path(char **abs_path_name, char **cpy_filename, char **cmdname);

void execution_helper(shell_cmd *head, int bytes, char **input_line,
		char *file);
void execute_path(shell_cmd *head, int n, char *file);
void execution_process(char *file);
int _read_user_input(char *line);
char *_memset(char *s, char value, unsigned int num);
void (*func_ptr(char *str))(char *);
void free_node(shell_cmd *head);
void display_prompt(void);
int _putchar(char c);
void _puts(char *str);
void env(char *en __attribute__((unused)));
void _error(char *file, int n, char *cmdname);
void print_number(int n);
int _putchar_errno(char character);


#endif
