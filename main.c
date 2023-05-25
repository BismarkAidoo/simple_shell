#include "shell.h"

/**
 * main - entry to main function to execute code
 *
 *
 * Return: Always (0) success
 */

int main(void)
{
	char *prompt = "McAnn$  ";
	char *input;
	char *argument[MAX_ARGUMENTS];
	char *token;
	int arg_count = 0;
	char **args;

	char *path = _getenv("PATH");
	pid_t child_pid;

	_setenv("PATH", "/bin", 1);

	while (1)
	{
		printPrompt(prompt);
		input = readInput();
		args = handle_args(input);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(input);
				exit(0);
			}
			if (_strcmp(command, "env") == 0)
			{
				print_environment();
				free(args);
				free(input);
				continue;
			}
			token = strtok(command, " ");
			while (token != NULL && arg_count < MAX_ARGUMENTS)
			{
				arguments[args_count] = token;
				arg_count++;
				token = strtok(NULL, " ");
			}
			arguments[arg_count] = NULL;
			if (access(arguments[0], X_OK) != 0)
			{
				handle_path(argument[0], arguments);
			}
			else
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("fork");
				}
				else if (child_pid == 0)
				{
					execvp(arguments[0], arguments);
					perror("execvp");
					exit(EXIT_FAILURE);
				}
				else
				{
					int status;

					waitpid(child_pid, &status, 0);
				}
			}
		}
		free(args);
		free(input);

	}
	return (0);
}
