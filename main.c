#include "shell.h"

/**
 * execute_path - execute non built_in commands
 * @head: pointer to the node structure for commands
 * @n: process count
 * @file: the name of the shell's executable file
 * Return: nothing.
 */
void execute_path(shell_cmd *head, int n, char *file)
{
	pid_t child_process;
	char *filename;
	int status;

	filename = search_path_and_create(head->command);
	if (filename != NULL)
	{
		free(head->command);
		head->command = NULL;
		head->args[0] = NULL;
		head->command = filename;
		head->args[0] = filename;

		child_process = fork();
		if (child_process == 0 &&
				access(head->command, X_OK) == 0)
		{
			if (execve(head->command, head->args,
						environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(child_process, &status, 0);
	}
	else
		_error(file, n, head->command);

}

/**
 * execution_helper - a branch process of the execution_process
 * @head: pointer to the head node representing the command structure
 * @bytes: number of bytes read from user input
 * @input_line: pointer to the user input.
 * @file: shell's executable filename.
 * Return: void.
 */
void execution_helper(shell_cmd *head, int bytes,
		char **input_line, char *file)
{
	char *line = NULL;
	void (*built_in_func)(char *);
	static int count;

	if (bytes > 0)
	{
		count++;
		create_command_buf(&head, *input_line);

		if (strcmp(head->command, "exit") == 0)
		{
			free_node(head);
			free(*input_line);
			exit(EXIT_SUCCESS);
		}

		built_in_func = func_ptr(head->command);
		if (built_in_func != NULL)
		{
			built_in_func(head->args[1]);
		}
		else
		{
			execute_path(head, count, file);
		}
		free_node(head);
		head = NULL;
	}
	free(line);
	line = NULL;
}

/**
 * execution_process - shell's execution process.
 * @file: shell's executable filename.
 * Return: void.
 */
void execution_process(char *file)
{
	ssize_t bytes;
	shell_cmd *head = NULL;
	char *input_line = NULL;

	input_line = (char *)malloc(sizeof(char) * 1024);
	if (input_line == NULL)
		exit(EXIT_FAILURE);
	bytes = _read_user_input(input_line);
	if (bytes == -1)
	{
		free(input_line);
		exit(EXIT_FAILURE);
	}
	input_line[bytes] = '\0';
	if (bytes > 0)
	{
		execution_helper(head, bytes, &input_line, file);
	}
	free(input_line);
	input_line = NULL;
}

/**
 * func_ptr - looks any funtion matching str.
 * @str: input string to look for.
 * Return: pointer to a function that takes a string
 * argv as input and returns void
 *
 */

void (*func_ptr(char *str))(char *)
{
	int i = 0;

	built_in cmd[] = {
		{"env", env},
		{NULL, NULL}
	};

	while (cmd[i].cmdname != NULL)
	{
		if (strcmp(cmd[i].cmdname, str) == 0)
		{
			return (cmd[i].function);
		}
		i++;
	}
	return (NULL);
}

/**
 * main - shell's entry point for either interactive or
 * non-interactive mode
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		do {
			signal(SIGINT, handle_sigint);
			display_prompt();
			execution_process(argv[0]);
		} while (1);
	}
	else
		execution_process(argv[0]);
	return (0);
}
